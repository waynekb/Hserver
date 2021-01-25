#ifndef _HSVR_H
#define _HSVR_H

#include <sys/event.h>
#include "happ/happ.h"
#include "hkq.h"

using namespace happ;
namespace hsvr {

class HAppSvr : public Happ {
 public:
  HAppSvr() {
  }

  virtual ~HAppSvr() {
  }
  virtual int OnUpdate();
  virtual int OnInit();

 private:
};  // namespace happ

}  // namespace hsvr

#endif