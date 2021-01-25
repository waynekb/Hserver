#include "happ.h"
#include "hlog/hlog.h"
#include "unistd.h"

using namespace happ;

static HappBase* h_app = nullptr;

HappBase::HappBase() {
  if (h_app != nullptr) {
    HLOG_WARN("Only allow one\n");
    abort();
  }
  h_app = this;
}

HappBase::~HappBase() {
  if (h_app != nullptr) {
    h_app = nullptr;
  }
}

HappBase* HappBase::GetApp() {
  return h_app;
}

int Happ::Run() {
  GetLogMod()->Init_log(HlogMod::H_LEVEL::DEBUG,
                        "/Users/waynebfhu/Documents/study/H3_server/logs/hsvr_log.log");
  OnInit();
  while (1) {
    if (m_stopflag) {
      break;
    }
    if (m_reloadconf) {
      OnReload();
    }
    OnUpdate();
    OnTick();
    sleep(1);
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
