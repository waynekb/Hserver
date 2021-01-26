#ifndef _HKQ_H
#define _HKQ_H
#include <sys/types.h>
#include "hchannelmgr.h"

namespace hsvr_base {

class Hkq : public Singleton<Hkq> {
 public:
  Hkq() : m_kq(0) {
  }
  virtual ~Hkq() {
  }

  int Open_hkq();
  int Loop_hkq();
  void Close_hkq();

  int Add_event(int fd, int16_t filter);
  int Del_event(int fd, int16_t filter);

 private:
  int m_kq;
};
}  // namespace hsvr_base
#endif