#ifndef _HAPP_HAPP_H
#define _HAPP_HAPP_H
#include "common/hobject.h"

namespace happ {

class HappBase : public Nocopyable {
 public:
  HappBase();
  virtual ~HappBase();

  static HappBase* GetApp();
};

class Happ : public HappBase {
 public:
  Happ() : m_stopflag(false), m_reloadconf(false) {
  }
  virtual ~Happ() {
  }

  int Run();

  void SetStop() {
    m_stopflag = true;
  }

  void SetReload() {
    m_reloadconf = true;
  }

  virtual int OnInit();
  virtual int OnTest() {
    return 0;
  }

  //必须重写OnUpdate()
  virtual int OnUpdate() = 0;

  virtual int OnTick();

  virtual int OnReload();

 private:
  bool m_stopflag;
  bool m_reloadconf;
};

}  // namespace happ

#endif