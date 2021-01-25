
#include <string>
#include "hlog/hlog.h"
#include "hsvr/hsvr.h"

using namespace std;
using namespace hsvr;

int main(int argc, char** argv) {
  HAppSvr appsvr;
  appsvr.Run();
  return 0;
}
