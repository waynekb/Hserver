#include "hsvr.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "hchannelmgr.h"
#include "hlog/hlog.h"
#include "htcpchannel.h"

using namespace hsvr;

int HAppSvr::OnUpdate() {
  HLOG_DEBUG("loop kq\n");
  return Hkq::GetInstance()->Loop_hkq();
}

int HAppSvr::OnInit() {
  //打开tcp listen
  ListenChannel* listen = ListenChannel::GetInstance();
  const char* ip = "127.0.0.1";
  int fd = listen->Open(ip, 3260);
  HLOG_DEBUG("\n");
  if (fd == -1) {
    HLOG_ERR("Listen Open fail\n");
    return -1;
  }
  HLOG_DEBUG("\n");
  //打开kqueue，并把listen加入到kqueue
  Hkq* kq = Hkq::GetInstance();
  int res = kq->Open_hkq();
  if (res == -1) {
    HLOG_ERR("kqueue Open fail\n");
    return -1;
  }
  HLOG_DEBUG("\n");
  res = kq->Add_event(fd, EVFILT_READ);
  HLOG_DEBUG("add event res=%d\n", res);
  if (res != 0) {
    HLOG_ERR("kqueue add event fail\n");
    return -1;
  }
  HLOG_DEBUG("\n");
  //把listen 加入到监听管理模块
  HMonitChannelMgr* mgr = HMonitChannelMgr::GetInstance();
  mgr->Add(fd, (Channel*)listen);
  return 0;
}