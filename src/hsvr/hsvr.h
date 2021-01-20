#ifndef _HSVR_H
#define _HSVR_H

#include <sys/event.h>
#include "happ/happ.h"

namespace happ {

class HappSvr : public Happ {
 public:
  HappSvr() : m_svrfd(0) {
  }

  virtual ~HappSvr() {
  }
  virtual int OnUpdate();
  virtual int OnInit();

 private:
  int Add_moni_event(int fd);
  int Del_moni_event(int fd);
  int m_svrfd;
  int m_kq;

};  // namespace happ

}  // namespace happ

#endif