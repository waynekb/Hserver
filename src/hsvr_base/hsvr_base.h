#ifndef _HSVRBASE_H
#define _HSVRBASE_H

#include <sys/event.h>
#include "happ/happ.h"
#include "hfactory.h"
#include "hkq.h"
#include "hlog/hlog.h"
#include "htaskmgr.h"

using namespace happ;

namespace hsvr_base {

struct HChannelContext;

class HAppSvrBase : public Happ {
 public:
  HAppSvrBase() {
  }

  virtual ~HAppSvrBase(){};

  virtual int OnUpdate();
  virtual int OnInit();

  virtual int DispatchMsg(const void* buf, size_t size, HChannelContext* ctx) {
    return 0;
  };

 private:
};

template <typename MsgObj>
class HAppSvrImpl : public HAppSvrBase {
 public:
  virtual int DispatchMsg(const void* buf, size_t size, HChannelContext* ctx);

 private:
};

template <typename MsgObj>
int HAppSvrImpl<MsgObj>::DispatchMsg(const void* buf, size_t size, HChannelContext* ctx) {
  MsgObj msg;
  msg.ParseFromArray(buf, size);
  uint32_t cmd = msg.head().cmd();
  HTaskFactory* factory = HTaskFactory::GetInstance();
  HTaskBase* task = factory->CreateTask(cmd);
  if (task == NULL) {
    return -1;
  }
  int ret = task->_Start(buf, size, ctx);

  factory->ReleaseTask(task);
  // if (task->) HTaskMgr::GetInstance()->PendTask(task);
  return ret;
}

}  // namespace hsvr_base

#endif