#include "happ_base.h"
#include "hlog/hlog.h"

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
