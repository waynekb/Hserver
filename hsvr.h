#ifndef _HSVR_H
#define _HSVR_H

#include "happ/happ.h"
#include <sys/event.h>

namespace happ {

class HappSvr : public Happ {
public:
  HappSvr() : m_svrfd(0), m_num(0) {}

  virtual ~HappSvr() {}
  int Svrrun();
  virtual int OnUpdate();
  virtual int OnInit();
  virtual int OnTest();

private:
  int m_svrfd;
  struct kevent m_lis_event[1024];
  struct kevent m_events[1024];
  int m_num;
  char m_buff[1024];
  int m_kq;

}; // namespace happ

} // namespace happ

#endif