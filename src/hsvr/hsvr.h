#ifndef _HSVR_H
#define _HSVR_H

#include <sys/event.h>
#include "happ/happ.h"

namespace happ {

class HappSvr : public Happ {
 public:
  HappSvr() {
  }
  ~HappSvr() {
  }

  virtual int OnUpdate() {
    return 1;
  }

  int OnInit();
};

}  // namespace happ

#endif