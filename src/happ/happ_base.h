#ifndef _HAPP_HAPP_BASE_H
#define _HAPP_HAPP_BASE_H

#include "unistd.h"
namespace happ {

struct HappCTX {
  int argc;
  char** argv;
  void* pragma;

  HappCTX() {
    ClearCtx();
  }

  void ClearCtx() {
    argc = 0;
    argv = nullptr;
    pragma = nullptr;
    return;
  }
};

typedef struct HappCTX HAPPCTX;
typedef struct HappCTX* PTHAPPCTX;

class Nocopyable {
 public:
  Nocopyable() {
  }
  virtual ~Nocopyable() {
  }

 protected:
  Nocopyable(const Nocopyable&) {
  }
};

class HappBase : public Nocopyable {
 public:
  HappBase();
  virtual ~HappBase();

  HappBase* GetApp();
};

}  // namespace happ

#endif