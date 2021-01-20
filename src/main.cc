
#include <string>
#include "hlog/hlog.h"
#include "hsvr/hsvr.h"

using namespace std;
using namespace happ;

int main(int argc, char** argv) {
  HappSvr appsvr;
  appsvr.Run();
  return 0;
}
