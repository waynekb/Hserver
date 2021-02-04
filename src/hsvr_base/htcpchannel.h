#ifndef _HTCPCHANNEL_H
#define _HTCPCHANNEL_H
#include <arpa/inet.h>
#include "common/hobject.h"
#include "hchannel.h"
#include "hsocket.h"

namespace hsvr_base {

class ListenChannel : public Singleton<ListenChannel>, public HChannel {
 public:
  ListenChannel() {
  }

  virtual ~ListenChannel() {
  }

  virtual int Open(const char *ip, short port);
  virtual void Close();

  virtual int HandleInput();
  virtual int HandleOutput(const void *data, size_t size, HChannelContext *ctx);
};

class HTcpChannel : public HChannel {
 public:
  HTcpChannel() {
  }

  virtual ~HTcpChannel() {
  }

  virtual void Close();

  int FreeHandle();

  virtual int HandleInput();
  virtual int HandleOutput(const void *data, size_t size, HChannelContext *ctx);
};

}  // namespace hsvr_base

#endif