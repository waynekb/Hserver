#ifndef _HCHANNEL_H
#define _HCHANNEL_H
#include <netinet/in.h>
#include "hsocket.h"
#include "sys/types.h"

namespace hsvr_base {

class HChannel;
enum { NULL_CHANNEL = 0, TCP_CHANNEL, UDP_CHANNEL };
struct TcpContext {
  in_addr_t from_ip;
  uint16_t from_port;
  int fd;
};

struct HChannelContext {
  HChannel* m_channel;
  short m_channel_type;

  union {
    TcpContext tcp;
  };

  HChannelContext() : m_channel(NULL), m_channel_type(NULL_CHANNEL){};
  HChannelContext(HChannel* channel, short type) : m_channel(channel), m_channel_type(type){};
};

class HChannel {
 public:
  HChannel() {
  }
  virtual ~HChannel() {
  }
  virtual int Open() {
    return 0;
  };

  virtual int Open(const char* ip, short port) {
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
  virtual int HandleOutput(const void* data, size_t size, HChannelContext* ctx) = 0;

  void SetSockaddr(sockaddr_in* sock) {
    m_addr = *sock;
  }

 protected:
  sockaddr_in m_addr;
  HSocket m_sock;
};

}  // namespace hsvr_base

#endif