
#include <string>
#include "hlog/hlog.h"
#include "hmessage/hmessage.pb.h"
#include "hsvr_base/hsvr_base.h"
#include "hsvr_base/hthreadpool.h"
#include "mysql/mysql.h"

using namespace std;
using namespace hsvr_base;

class GetStudentInfoReq : public HTaskImpl<HPR_SvrMsg> {
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
    res->set_college("usetc");
    SendMsg();
    return 0;
  }
};

REGISTER_ASYNC_TASK(CMD_GETSTUDENTINFOREQ, GetStudentInfoReq, "get_student_info_req");

class HApp : public HAppSvrImpl<HPR_SvrMsg> {};

class TEST : public HThreadPool {
 public:
  TEST() : n(0){};
  virtual int ThreadProc() {
    n++;
    printf("%d\n", n);
    return 0;
  }

 private:
  int n;
};

int main(int argc, char** argv) {
  using namespace hsvr_base;
  GetLogMod()->Init_log(HlogMod::H_LEVEL::DEBUG,
                        "/Users/waynebfhu/Documents/study/H3_server/logs/hsvr_log.log");

  TEST pool;
  pool.Start(20);
  pool.Stop();
}

/*

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

  MYSQL_RES* result;
  const char* quecmd = "select * from student";
  int res = mysql_real_query(mysql, quecmd, strlen(quecmd));
  if (res == 0) {
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
  mysql_close(mysql);
  return 0;
}
*/