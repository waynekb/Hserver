
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

int main(int argc, char** argv) {
  HApp app;
  app.Run();
  return 0;
}