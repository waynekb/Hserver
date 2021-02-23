#include "hmysqlcaller.h"
#include "hchannel.h"
#include "hlog/hlog.h"
#include "htaskmgr.h"

using namespace hsvr_base;

bool HMysqlCallback::CallbackIsComplete() {
  if (call_num <= 0) {
    call_num = 0;
    return true;
  } else {
    return false;
  }
}

int HMysqlCallback::DoMysqlResponse(HSqlCallTask* calltask) {
  MysqlResponse(calltask);
  if (calltask->result) {
    mysql_free_result(calltask->result);
  }
  Subcall();
  return 0;
}

int HMysqlCaller::AddCall(HMysqlCallback* sqlbase, uint32_t taskid, const char* sql) {
  void* call = GetFreeBox();
  if (!call) {
    return -1;
  }
  HSqlCallTask* sqlcall = (HSqlCallTask*)call;
  sqlcall->taskid = taskid;
  int len = strlen(sql);
  strncpy(sqlcall->sql, sql, len);
  sqlcall->sql[len] = '\0';
  sqlcall->sqlcallbase = sqlbase;
  AddEvent(call);
  sqlbase->Addcall();
  return 0;
}

int HMysqlCaller::DoResponse() {
  SQLCALLTASKQUEUEPTR queueptr = nullptr;
  {
    std::unique_lock<std::mutex> lock(m_resmtx);
    if (m_queue->size() <= 0) {
      return 0;
    }
    if (m_queue == &m_queue1) {
      queueptr = &m_queue1;
      m_queue = &m_queue2;

    } else if (m_queue == &m_queue2) {
      queueptr = &m_queue2;
      m_queue = &m_queue1;

    } else {
      SQLCALLTASKQUEUE empty1;
      SQLCALLTASKQUEUE empty2;
      std::swap(empty1, m_queue1);
      std::swap(empty2, m_queue2);
      m_queue = &m_queue1;
    }

    int count = queueptr->size();
    for (int i = 0; i < count; i++) {
      HSqlCallTask* call = queueptr->front();
      HTaskBase* task = HTaskMgr::GetInstance()->FindTask(call->taskid);
      HMysqlCallback* callback = dynamic_cast<HMysqlCallback*>(task);
      callback->DoMysqlResponse(call);
      PushFreeList((void*)call);
      HTaskMgr::GetInstance()->InsertTaskToSet(call->taskid);
      queueptr->pop();
    }
    return 0;
  }
}
int HMysqlCaller::Start(int num) {
  m_queue = &m_queue1;
  InitFreeList();
  InitMysqlCon();
  HThreadPoolBase::Start(num);
  return 0;
}

int HMysqlCaller::Stop() {
  HLoopThreadPool::Stop();
  CloseMysqlCon();
  return 0;
}

void HMysqlCaller::InitFreeList() {
  if (m_initflag) {
    return;  //防止多次初始化，导致错误
  }
  for (int i = 0; i < MAXHCALLNUM; i++) {
    InitPushFreeList((void*)&m_callarray[i]);
  }
  m_initflag = true;
}

int HMysqlCaller::DoEvent(void* call) {
  HSqlCallTask* sqlcall = (HSqlCallTask*)call;
  int len = strlen(sqlcall->sql);
  const char* sql = (const char*)sqlcall->sql;
  int res = mysql_real_query(m_mysql, sql, len);
  if (res == 0) {
    MYSQL_RES* result = NULL;
    result = mysql_store_result(m_mysql);
    if (result) {
      sqlcall->result = result;
    } else {
      sqlcall->result = NULL;
    }
  } else {
    const char* erro = mysql_error(m_mysql);
    sqlcall->result = NULL;
    HLOG_ERR("%s\n", erro);
  }
  {
    std::unique_lock<std::mutex> lock(m_resmtx);
    m_queue->push(sqlcall);
  }
  // mysql_free_result(result);
  return 0;
}

int HMysqlCaller::InitMysqlCon() {
  m_mysql = mysql_init(NULL);
  mysql_options(m_mysql, MYSQL_SET_CHARSET_NAME, "utf8");
  MYSQL* tmp = mysql_real_connect(m_mysql, "localhost", "root", "wayne0720", "student", 0, NULL,
                                  CLIENT_MULTI_RESULTS);
  if (tmp == NULL) {
    HLOG_INFO("MYSQL connect fail\n");
    return -1;
  } else {
    HLOG_INFO("MYSQL connect succ\n");
  }
  return 0;
}

int HMysqlCaller::CloseMysqlCon() {
  mysql_close(m_mysql);
  return 0;
}