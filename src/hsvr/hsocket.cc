#include "hsocket.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include "hlog/hlog.h"

using namespace hsvr;
#define MAX_LISTENER 100

int HSocket::Open(int domain, int type) {
  m_fd = socket(domain, type, 0);
  if (m_fd < 0) {
    HLOG_WARN("create socket fail ret=%d\n", m_fd);
    return -1;
  }
  return 0;
}

void HSocket::Close() {
  if (m_fd > 0) {
    close(m_fd);
  }
  m_fd = -1;
}

int HSocket::Bind(const sockaddr* addr) {
  int ret = bind(m_fd, addr, sizeof(struct sockaddr));
  if (ret != 0) {
    HLOG_ERR("bind socket fail ret=%d\n", ret);
    return -1;
  }
  return 0;
}

int HSocket::Listen() {
  int ret = listen(m_fd, MAX_LISTENER);
  if (ret < 0) {
    HLOG_ERR("listen socket failed ret=%d \n", ret);
    return -1;
  }
  return 0;
}

int HSocket::Accept(sockaddr* cli_addr, socklen_t* len) {
  int fd = accept(m_fd, cli_addr, len);
  if (fd < 0) {
    HLOG_WARN("accept new connection fail\n");
    return -1;
  }
  return fd;
}

int HSocket::Send(const void* buf, int size) {
  return send(m_fd, buf, size, 0);
}

int HSocket::Recv(void* buf, int size) {
  return recv(m_fd, buf, size, 0);
}