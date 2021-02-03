#include "hsvr_base.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "hchannelmgr.h"
#include "hlog/hlog.h"
#include "htcpchannel.h"

using namespace hsvr_base;

int HAppSvrBase::OnUpdate() {
  return Hkq::GetInstance()->Loop_hkq();
}

int HAppSvrBase::OnInit() {
  //打开tcp listen
  ListenChannel* listen = ListenChannel::GetInstance();
  const char* ip = "127.0.0.1";
  int fd = listen->Open(ip, 3260);
  if (fd == -1) {
    HLOG_ERR("Listen Open fail\n");
    return -1;
  }
  //打开kqueue，并把listen加入到kqueue
  Hkq* kq = Hkq::GetInstance();
  int res = kq->Open_hkq();
  if (res == -1) {
    HLOG_ERR("kqueue Open fail\n");
    return -1;
  }
  res = kq->Add_event(listen->Getfd(), EVFILT_READ);
  if (res != 0) {
    HLOG_ERR("kqueue add event fail\n");
    return -1;
  }
  //把listen 加入到监听管理模块
  HMonitChannelMgr* mgr = HMonitChannelMgr::GetInstance();
  mgr->Add(listen->Getfd(), (HChannel*)listen);

  //初始化channelpool资源池
  HTcpChannelPool::GetInstance()->InitPool();
  return 0;
}