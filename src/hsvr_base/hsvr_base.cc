#include "hsvr_base.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "hchannelmgr.h"
#include "hlog/hlog.h"
#include "hmysqlcaller.h"
#include "htcpchannel.h"

using namespace hsvr_base;

int HAppSvrBase::OnUpdate() {
  Hkq::GetInstance()->Loop_hkq();             // kqueue接收请求
  HMysqlCaller::GetInstance()->DoResponse();  // Mysqlcall处理response;
  HTaskMgr::GetInstance()->IsTaskComplete();  //检查任务是否完成。
  return 0;
}

int HAppSvrBase::OnInit() {
  //打开tcp listen
  ListenChannel* listen = ListenChannel::GetInstance();
  const char* ip = "127.0.0.1";
  listen->Open(ip, 3260);

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

  //打开mysqlcaller
  HMysqlCaller::GetInstance()->Start();
  return 0;
}