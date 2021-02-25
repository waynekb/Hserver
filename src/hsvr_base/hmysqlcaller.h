#ifndef _HMYSQLCALLER_H
#define _HMYSQLCALLER_H
#include <mutex>
#include <queue>
#include <vector>
#include "common/hobject.h"
#include "hasynctask.h"
#include "hthreadpool.h"
#include "mysql/mysql.h"

#define MAXHCALLNUM 10
namespace hsvr_base {

struct HSqlCallTask;

class HMysqlCallback : public HMysqlCallbackBase {
 public:
  HMysqlCallback() : call_num(0){};
  ~HMysqlCallback(){};
  virtual bool CallbackIsComplete();

  virtual int MysqlResponse(HSqlCallTask* calltask) = 0;
  virtual int DoMysqlResponse(HSqlCallTask* calltask);

  void Addcall() {
    call_num++;
  }

  void Subcall() {
    call_num--;
  }

  int Getcallnum() {
    return call_num;
  }

 private:
  int call_num;

 private:
};

struct HSqlCallTask {
 public:
  char sql[512];
  // char calltitle[64];
  uint32_t taskid;
  std::vector<MYSQL_RES*> results;
};

class HMysqlCaller : public Singleton<HMysqlCaller>, public HLoopThreadPool, public HAsyncTaskbase {
 public:
  HMysqlCaller() : m_initflag(false), m_queue(NULL){};
  virtual ~HMysqlCaller(){};

  int AddCall(HMysqlCallback* sqlbase, uint32_t taskid, const char* sql);
  virtual int DoResponse();

  int Start(int num = 8);
  int Stop();
  virtual int DoEvent(void* call);

 private:
  int InitMysqlCon(int num);
  int CloseMysqlCon();
  void InitFreeList();

  HSqlCallTask m_callarray[MAXHCALLNUM];
  bool m_initflag;

  typedef std::queue<HSqlCallTask*> SQLCALLTASKQUEUE;
  typedef SQLCALLTASKQUEUE* SQLCALLTASKQUEUEPTR;

  SQLCALLTASKQUEUE m_queue1;
  SQLCALLTASKQUEUE m_queue2;

  SQLCALLTASKQUEUEPTR m_queue;

  std::mutex m_resmtx;
  std::vector<MYSQL*> m_mysqls;
};

}  // namespace hsvr_base

#endif