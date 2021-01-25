#ifndef _HSOCKET_H
#define _HSOCKET_H

#include <sys/socket.h>
#include <unistd.h>
#include "common/hobject.h"

namespace hsvr {

class HSocket : public Nocopyable {
 public:
  HSocket() : m_fd(-1) {
  }

  ~HSocket() {
    Close();
  }

  int Open(int domain, int type);
  void Close();

  int Bind(const sockaddr* sockaddr);
  int Listen();

  // int Connect();
  int Accept(sockaddr* cli_addr, socklen_t* len);
  int Send(const void* buf, int size);
  int Recv(void* buf, int size);

  inline int Getfd() {
    return m_fd;
  }

  inline int Attach(int fd) {
    int atp = m_fd;
    m_fd = fd;
    return atp;
  }

  inline int Detach() {
    int atp = m_fd;
    m_fd = -1;
    return atp;
  }

 private:
  int m_fd;
};
}  // namespace hsvr
#endif