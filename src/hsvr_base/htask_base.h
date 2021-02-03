#ifndef _HTASK_BASE_H
#define _HTASK_BASE_H
#include <stddef.h>
#include <stdint.h>

namespace hsvr_base {
class HTaskBase {
 public:
  HTaskBase() {
  }
  virtual ~HTaskBase(){};

  virtual int _Start(const void* data, size_t size) = 0;

  void SetCmd(uint32_t cmd);
  uint32_t GetCmd();

  void SetTaskId(uint32_t taskid);

  uint32_t GetTaskId();

 protected:
  uint32_t m_cmd;
  uint32_t m_taskid;
};

template <typename MsgObj>
class HTaskImpl : public HTaskBase {
 public:
  HTaskImpl(){};
  virtual ~HTaskImpl(){};
  virtual int Start(const MsgObj& msg) = 0;

  virtual int _Start(const void* data, size_t size) {
    MsgObj msg;
    msg.ParseFromArray(data, size);
    return Start(msg);
  }

 private:
};

#define REGISTER_ASYNC_TASK(cmd, class, name) \
  static HTaskRegister<cmd, class> class##_register_(name);

}  // namespace hsvr_base

#endif