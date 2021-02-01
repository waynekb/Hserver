#ifndef _HCHANNEL_H
#define _HCHANNEL_H
#include "hsocket.h"
#include "sys/types.h"

namespace hsvr_base {

class HChannel {
 public:
  HChannel() {
  }
  virtual ~HChannel() {
  }
  virtual int Open() {
    return 0;
  };

  virtual int Open(const char *ip, short port) {
    return 0;
  }

  inline int Attach(int fd) {
    return m_sock.Attach(fd);
  }
  virtual int Getfd() {
    return m_sock.Getfd();
  }
  virtual void Close() = 0;

  virtual int HandleInput() = 0;
  virtual int HandleOutput() = 0;

 protected:
  sockaddr_in m_addr;
  HSocket m_sock;
};

}  // namespace hsvr_base

#endif