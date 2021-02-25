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
    const HPR_GetStudentInfoReq& reqbody = msg.body().get_student_info_req();
    char sql[512] = {0};
    /*
    for (int i = 0; i < reqbody.roleids_size(); i++) {
      int size = strlen(sql);
      snprintf(sql + size, sizeof(sql) - size, "select * from student where stu_id=%d;",
               reqbody.roleids(i));
    }
    HMysqlCaller::GetInstance()->AddCall(this, m_taskid, (const char*)sql);
    */
    for (int i = 0; i < reqbody.roleids_size(); i++) {
      snprintf(sql, sizeof(sql), "select * from student where stu_id=%d;", reqbody.roleids(i));
      HMysqlCaller::GetInstance()->AddCall(this, m_taskid, (const char*)sql);
    }
    return 0;
  }

  int str2int(const char* str) {
    int i;
    sscanf(str, "%d", &i);
    return i;
  }

  int MysqlResponse(HSqlCallTask* calltask) {
    int count = calltask->results.size();
    HPR_GetStudentInfoRes* resbody = GetResponse()->mutable_body()->mutable_get_student_info_res();
    if (count == 0) {
      HLOG_INFO("QUERY mysql fail\n");
      resbody->set_err_code(-1);
      return 0;
    }
    for (int i = 0; i < count; i++) {
      MYSQL_RES* result = calltask->results[i];
      if (result) {
        MYSQL_ROW sql_row;
        while ((sql_row = mysql_fetch_row(result)) != NULL) {
          resbody->set_err_code(0);
          HPR_StudentInfo* student = resbody->add_students();
          int role_id = str2int((const char*)sql_row[0]);
          student->set_roleid(role_id);
          student->set_name((const char*)sql_row[1]);
          int age = str2int((const char*)sql_row[2]);
          student->set_age(age);
          int grade = str2int((const char*)sql_row[3]);
          student->set_grade(grade);
          student->set_date((const char*)sql_row[4]);
        }
      }
    }
    return 0;
  }
};

REGISTER_ASYNC_TASK(CMD_GETSTUDENTINFOREQ, GetStudentInfoReq, "get_student_info_req");

}  // namespace hsvr_base
