#include "hmessage/hmessage.pb.h"
#include "hsvr_base/hmysqlcaller.h"
#include "hsvr_base/htask_base.h"

namespace hsvr_base {

class HSvrTask : public HTaskImpl<HPR_SvrMsg>, public HMysqlCallback {
 public:
  virtual bool IsComplete() {
    return HMysqlCallback::CallbackIsComplete();
  }

  virtual int MysqlResponse(HSqlCallTask* calltask) {
    return 0;
  }

 private:
};

class GetStudentInfoReq : public HSvrTask {
 public:
  int Start(const HPR_SvrMsg& msg) {
    // const HPR_MsgHead& head = msg.head();
    const HPR_GetStudentInfoReq& reqbody = msg.body().get_student_info_req();
    char sql[128] = {0};
    int role_id = reqbody.roleid();
    snprintf(sql, sizeof(sql), "select * from student where stu_id=%d", role_id);
    HMysqlCaller::GetInstance()->AddCall(this, m_taskid, (const char*)sql);
    return 0;
    /*
    HLOG_INFO("cmd=%d, seq=%d, role_id=%d\n", head.cmd(), head.seqno(), reqbody.roleid());
    HPR_GetStudentInfoRes* res = GetResponse()->mutable_body()->mutable_get_student_info_res();
    res->set_err_code(0);
    res->set_name("wayne");
    res->set_roleid(1024326);
    res->set_age(18);
    res->set_date("usetc");
    SendMsg();
    return 0;
    */
  }

  int str2int(const char* str) {
    int i;
    sscanf(str, "%d", &i);
    return i;
  }

  int MysqlResponse(HSqlCallTask* calltask) {
    MYSQL_ROW sql_row;
    MYSQL_RES* result = calltask->result;
    HPR_GetStudentInfoRes* resbody = GetResponse()->mutable_body()->mutable_get_student_info_res();
    while ((sql_row = mysql_fetch_row(result)) != NULL) {
      resbody->set_err_code(0);
      int role_id = str2int((const char*)sql_row[0]);
      resbody->set_roleid(role_id);
      resbody->set_name((const char*)sql_row[1]);
      int age = str2int((const char*)sql_row[2]);
      resbody->set_age(age);
      resbody->set_date((const char*)sql_row[4]);
    }
    SendMsg();
    return 0;
  }
};

REGISTER_ASYNC_TASK(CMD_GETSTUDENTINFOREQ, GetStudentInfoReq, "get_student_info_req");

}  // namespace hsvr_base
