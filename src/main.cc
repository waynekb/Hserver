
#include <string>
#include "hlog/hlog.h"
#include "hmessage/hmessage.pb.h"
#include "hsvr_base/hsvr_base.h"

using namespace std;
using namespace hsvr_base;

class GetStudentInfoReq : public HTaskImpl<HPR_SvrMsg> {
 public:
  virtual int Start(const HPR_SvrMsg& msg) {
    const HPR_MsgHead& head = msg.head();
    const HPR_GetStudentInfoReq& reqbody = msg.body().get_student_info_req();
    HLOG_INFO("cmd=%d, seq=%d, role_id=%d\n", head.cmd(), head.seqno(), reqbody.roleid());
    return 0;
  }
};

REGISTER_ASYNC_TASK(CMD_GETSTUDENTINFOREQ, GetStudentInfoReq, "get_student_info_req");

class HApp : public HAppSvrImpl<HPR_SvrMsg> {};

int main(int argc, char** argv) {
  HApp appsvr;
  appsvr.Run();
  return 0;
}
