#ifndef _HAPP_HAPP_BASE_H
#define _HAPP_HAPP_BASE_H

#include "unistd.h"
namespace happ {

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