
#include <exception>
#include <string>
#include "hlog/hlog.h"
#include "hmessage/hmessage.pb.h"
#include "hsvr_base/hmysqlcaller.h"
#include "hsvr_base/hsvr_base.h"
#include "hsvr_base/hthreadpool.h"
#include "mysql/mysql.h"

using namespace std;
using namespace hsvr_base;

/*
class GetStudentInfoReqtest : public HTaskImpl<HPR_SvrMsg> {
 public:
  virtual int Start(const HPR_SvrMsg& msg) {
    const HPR_MsgHead& head = msg.head();
    const HPR_GetStudentInfoReq& reqbody = msg.body().get_student_info_req();
    HLOG_INFO("cmd=%d, seq=%d, role_id=%d\n", head.cmd(), head.seqno(), reqbody.roleid());
    HPR_GetStudentInfoRes* res = GetResponse()->mutable_body()->mutable_get_student_info_res();
    res->set_err_code(0);
    res->set_name("wayne");
    res->set_roleid(1024326);
    res->set_age(18);
    res->set_date("usetc");
    SendMsg();
    return 0;
  }
};

REGISTER_ASYNC_TASK(2, GetStudentInfoReqtest, "get_student_info_req_test");
*/
class HApp : public HAppSvrImpl<HPR_SvrMsg> {};

using namespace hsvr_base;
/*
int main(int argc, char** argv) {
  printf("sdg\n");
  GetLogMod()->Init_log(HlogMod::H_LEVEL::DEBUG,
                        "/Users/waynebfhu/Documents/study/H3_server/logs/hsvr_log.log");
  printf("sdf\n");

  HLoopThreadPool pool;
  try {
    printf("44\n");
    HMysqlCaller caller;
    printf("45\n");
  } catch (exception& e) {
    printf("excp\n");
  }
  printf("4444\n");
  return 0;
}
*/
/*
int main(int argc, char** argv) {
  using namespace hsvr_base;
  GetLogMod()->Init_log(HlogMod::H_LEVEL::DEBUG,
                        "/Users/waynebfhu/Documents/study/H3_server/logs/hsvr_log.log");
  HMysqlCaller sqlcall;
  sqlcall.Start(1);
  const char* sql1 = "select * from student where stu_id=1";
  // const char* sql2 = "select * from student where stu_id=2";
  // const char* sql3 = "select * from student where stu_id=3";
  HLOG_DEBUG("\n");
  sqlcall.AddCall(NULL, 1, sql1);
  // sqlcall.AddCall(NULL, 2, sql2);
  // sqlcall.AddCall(NULL, 3, sql3);
  // sqlcall.Stop();
  HLOG_DEBUG("\n");
  sleep(5);
  return 0;
}
*/
/*
int query(MYSQL* mysql, const char* sql) {
  int res = mysql_real_query(mysql, sql, strlen(sql));
  if (res == 0) {
    MYSQL_RES* result;
    MYSQL_ROW sql_row;
    result = mysql_store_result(mysql);
    if (result) {
      int fields_num = mysql_num_fields(result);
      printf("fileds = %d\n", fields_num);
      MYSQL_FIELD* field;
      while ((field = mysql_fetch_field(result)) != NULL) {
        printf("filedname %s\n", field->name);
      }
      while ((sql_row = mysql_fetch_row(result)) != NULL) {
        printf("ID=%s, name:%s, age=%s, grade=%s, date=%s\n", sql_row[0], sql_row[1], sql_row[2],
               sql_row[3], sql_row[4]);
      }
    }
    mysql_free_result(result);
  }
  return 0;
}
int main(int argc, char** argv) {
  // HApp appsvr;
  // appsvr.Run();

  MYSQL* mysql = mysql_init(NULL);
  mysql_options(mysql, MYSQL_SET_CHARSET_NAME, "utf8");
  MYSQL* tmp = mysql_real_connect(mysql, "localhost", "root", "wayne0720", "student", 0, NULL,
                                  CLIENT_MULTI_RESULTS);
  if (tmp == NULL) {
    printf("connect fail\n");
  } else {
    printf("connect succ\n");
  }

  const char* sql1 = "select * from student where stu_id=1";
  const char* sql2 = "select * from student where stu_id=2";
  const char* sql3 = "select * from student where stu_id=3";
  query(mysql, sql1);
  query(mysql, sql2);
  query(mysql, sql3);

  mysql_close(mysql);
  return 0;
}
*/

int main(int argc, char** argv) {
  HApp app;
  app.Run();
  return 0;
}