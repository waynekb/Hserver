
#include <string>
#include "hlog/hlog.h"
#include "hmessage/hmessage.pb.h"
#include "hsvr_base/hsvr_base.h"

using namespace std;
using namespace hsvr_base;

class Task : public HTaskImpl<HPR_SvrMsg> {
 public:
  virtual int Start(const HPR_SvrMsg& msg) {
    const HPR_MsgHead& head = msg.head();
    const HPR_MsgBody& body = msg.body();
    HLOG_INFO("cmd=%d, seq=%d, name=%s, age=%d\n", head.cmd(), head.seq(), body.name().c_str(),
              body.age());
    return 0;
  }
};

REGISTER_ASYNC_TASK(1, Task, "post_info");

class HApp : public HAppSvrImpl<HPR_SvrMsg> {};

int main(int argc, char** argv) {
  HApp appsvr;
  appsvr.Run();
  return 0;
}
