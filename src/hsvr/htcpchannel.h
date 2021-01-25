#ifndef _HTCPCHANNEL_H
#define _HTCPCHANNEL_H
#include <arpa/inet.h>
#include "common/hobject.h"
#include "hchannel.h"
#include "hsocket.h"

namespace hsvr {

class ListenChannel : public Singleton<ListenChannel>, private Channel {
 public:
  ListenChannel() {
  }

  virtual ~ListenChannel() {
  }

  virtual int Open(const char *ip, short port);
  virtual void Close();

  virtual int HandleInput();
  virtual int HandleOutput();
};

class HTcpChannel : private Channel {
 public:
  HTcpChannel() {
  }

  virtual ~HTcpChannel() {
  }

  virtual void Close();

  virtual int HandleInput();
  virtual int HandleOutput();
};

}  // namespace hsvr

#endif