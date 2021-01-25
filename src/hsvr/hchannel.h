#ifndef _HCHANNEL_H
#define _HCHANNEL_H
#include "hsocket.h"
#include "sys/types.h"

namespace hsvr {

class Channel {
 public:
  Channel() {
  }
  virtual ~Channel() {
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
  virtual void Close() = 0;

  virtual int HandleInput() = 0;
  virtual int HandleOutput() = 0;

 protected:
  sockaddr_in m_addr;
  HSocket m_sock;
};

}  // namespace hsvr

#endif