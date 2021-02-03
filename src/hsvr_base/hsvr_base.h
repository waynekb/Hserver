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

class HAppSvrBase : public Happ {
 public:
  HAppSvrBase() {
  }

  virtual ~HAppSvrBase(){};

  virtual int OnUpdate();
  virtual int OnInit();

  virtual int DispatchMsg(const void* buf, size_t size) {
    return 0;
  };

 private:
};

template <typename MsgObj>
class HAppSvrImpl : public HAppSvrBase {
  virtual int DispatchMsg(const void* buf, size_t size);
};

template <typename MsgObj>
int HAppSvrImpl<MsgObj>::DispatchMsg(const void* buf, size_t size) {
  MsgObj msg;
  msg.ParseFromArray(buf, size);
  uint32_t cmd = msg.head().cmd();
  HTaskFactory* factory = HTaskFactory::GetInstance();
  HTaskBase* task = factory->CreateTask(cmd);
  int ret = task->_Start(buf, size);

  HTaskMgr::GetInstance()->PendTask(task);
  return ret;
}

}  // namespace hsvr_base

#endif