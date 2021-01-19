#include "happ.h"
#include "hlog/hlog.h"

using namespace happ;
int Happ::Run() {
  GetLogMod()->Init_log(HlogMod::H_LEVEL::DEBUG,
                        "/Users/waynebfhu/Documents/study/H3_server/logs/hsvr_log.log");
  OnInit();
  // OnTest();
  HLOG_DEBUG("RUN END\n");
  return 0;
  while (1) {
    if (m_stopflag) {
      break;
    }
    if (m_reloadconf) {
      OnReload();
    }
    OnUpdate();
    OnTick();
  }
  return 0;
}

int Happ::OnInit() {
  return 0;
}

int Happ::OnTick() {
  return 0;
}

int Happ::OnReload() {
  return 0;
}
