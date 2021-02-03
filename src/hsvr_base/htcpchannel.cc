#include "htcpchannel.h"
#include "hchannelmgr.h"
#include "hkq.h"
#include "hlog/hlog.h"
#include "hmessage/hmessage.pb.h"
#include "hsvr_base.h"
#include "sys/socket.h"

#define EVFILT_READ (-1)
#define EVFILT_WRITE (-2)

using namespace hsvr_base;

int ListenChannel::Open(const char *ip, short port) {
  m_addr.sin_family = AF_INET;
  m_addr.sin_port = htons(port);
  m_addr.sin_addr.s_addr = inet_addr(ip);

  if (m_sock.Open(AF_INET, SOCK_STREAM) == -1) {
    return -1;
  }
  if (m_sock.Bind((sockaddr *)&m_addr) == -1) {
    return -1;
  }
  if (m_sock.Listen() == -1) {
    return -1;
  }
  HLOG_INFO("listenChannel open succ\n");
  return Getfd();
}

int ListenChannel::HandleInput() {
  sockaddr addr;
  socklen_t len;
  int fd = m_sock.Accept(&addr, &len);
  if (fd == -1) {
    return -1;
  }
  HLOG_DEBUG("Accept fd=%d\n", fd);
  HChannel *ch = HTcpChannelPool::GetInstance()->GetNewChannel();
  if (ch == NULL) {
    HLOG_WARN("TcpChannelpool full\n");
    return -1;
  }
  ch->Attach(fd);
  Hkq::GetInstance()->Add_event(fd, EVFILT_READ);
  HMonitChannelMgr::GetInstance()->Add(fd, ch);
  return 0;
}

void ListenChannel::Close() {
  m_sock.Close();
}

int ListenChannel::HandleOutput() {
  return 0;
}

void HTcpChannel::Close() {
  m_sock.Close();
}

int HTcpChannel::HandleInput() {
  char buf[1024] = {0};
  // int size = m_sock.Recv(buf, 1024);
  int size = m_sock.Recv(buf, 1024);
  HAppSvrBase *happ = (HAppSvrBase *)HappBase::GetApp();
  return happ->DispatchMsg(buf, size);
}

int HTcpChannel::HandleOutput() {
  return 0;
}