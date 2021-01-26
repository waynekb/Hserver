
#include <string>
#include "hlog/hlog.h"
#include "hsvr_base/hsvr_base.h"
#include "proto/proto/hmessage.pb.h"

using namespace std;
using namespace hsvr_base;

int main(int argc, char** argv) {
  HAppSvr appsvr;
  appsvr.Run();
  return 0;
}
