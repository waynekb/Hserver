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
    HLOG_ERR("listenChannel open fail\n");
    return -1;
  }
  if (m_sock.Bind((sockaddr *)&m_addr) == -1) {
    HLOG_ERR("listenChannel bind fail\n");
    return -1;
  }
  if (m_sock.Listen() == -1) {
    HLOG_ERR("listenChannel listen fail\n");
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
  HChannel *ch = HTcpChannelPool::GetInstance()->GetNewChannel();
  if (ch == NULL) {
    HLOG_WARN("TcpChannelpool full\n");
    return -1;
  }
  ch->Attach(fd);
  ch->SetSockaddr((sockaddr_in *)&addr);
  Hkq::GetInstance()->Add_event(fd, EVFILT_READ);
  HMonitChannelMgr::GetInstance()->Add(fd, ch);
  return 0;
}

void ListenChannel::Close() {
  m_sock.Close();
}

int ListenChannel::HandleOutput(const void *data, size_t size, HChannelContext *ctx) {
  return 0;
}

void HTcpChannel::Close() {
  m_sock.Close();
}

int HTcpChannel::HandleInput() {
  char buf[1024] = {0};
  int size = m_sock.Recv(buf, 1024);
  if (size <= 0) {
    FreeHandle();
    return -1;
  }
  HAppSvrBase *happ = (HAppSvrBase *)HappBase::GetApp();
  HChannelContext ctx(this, TCP_CHANNEL);
  return happ->DispatchMsg(buf, size, &ctx);
}

int HTcpChannel::HandleOutput(const void *data, size_t size, HChannelContext *ctx) {
  int ret = m_sock.Send(data, size);
  if (ret != size) {
    HLOG_WARN("tcpchannel send msg not complete size=%d ret=%d\n", size, ret);
    return -1;
  }
  return 0;
}

int HTcpChannel::FreeHandle() {
  int fd = m_sock.Getfd();
  HMonitChannelMgr::GetInstance()->Del(fd);
  HTcpChannelPool::GetInstance()->AddFreeChannel(this);
  Hkq::GetInstance()->Del_event(fd, EVFILT_READ);  // 从kqueue中删除

  close(fd);
  return 0;
}