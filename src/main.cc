
#include <string>
#include "hlog/hlog.h"
#include "hsvr/hsvr.h"

using namespace std;
using namespace happ;

int main(int argc, char** argv) {
  GetLogMod()->Init_log(HlogMod::H_LEVEL::DEBUG,
                        "/Users/waynebfhu/Documents/study/H3_server/logs/hsvr_log.log");
  HappSvr appsvr;
  appsvr.Run();
  return 0;
}
