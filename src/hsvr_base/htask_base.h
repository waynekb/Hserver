#ifndef _HTASK_BASE_H
#define _HTASK_BASE_H
#include <stddef.h>
#include <stdint.h>
#include "hchannel.h"
#include "hfactory.h"
#include "hlog/hlog.h"
#include "string.h"

namespace hsvr_base {
class HTaskBase {
 public:
  HTaskBase() {
  }
  virtual ~HTaskBase(){};

  virtual int _Start(const void* data, size_t size, HChannelContext* ctx) = 0;

  virtual bool IsComplete() = 0;

  virtual int SendMsg() = 0;
  void SetCmd(uint32_t cmd);
  uint32_t GetCmd();

  void SetTaskId(uint32_t taskid);

  uint32_t GetTaskId();

 protected:
  uint32_t m_cmd;
  uint32_t m_taskid;

  HChannelContext m_channel_ctx;
};

/**使用模板，方便以后更改消息类型
 * 开发者只需要在实现子类的时候，传入新的消息类型即可。但是新的消息必须包含cmd和seqno等字段。
 * **/
template <typename MsgObj>
class HTaskImpl : public HTaskBase {
 public:
  HTaskImpl(){};
  virtual ~HTaskImpl(){};
  virtual int Start(const MsgObj& msg) = 0;

  virtual bool IsComplete() {
    return true;
  };

  virtual int _Start(const void* data, size_t size, HChannelContext* ctx) {
    MsgObj msg;
    msg.ParseFromArray(data, size);
    m_channel_ctx.m_channel = ctx->m_channel;
    m_channel_ctx.m_channel_type = ctx->m_channel_type;
    m_channel_ctx.tcp = ctx->tcp;

    m_res.mutable_head()->CopyFrom(msg.head());  //返回消息头信息默认和接收消息一致

    int ret = Start(msg);
    return ret;
  }

  virtual int SendMsg() {
    char buf[1024] = {0};
    m_res.SerializeToArray((void*)buf, 1024);
    return m_channel_ctx.m_channel->HandleOutput(buf, strlen(buf), &m_channel_ctx);
  }

  MsgObj* GetResponse() {
    return &m_res;
  }

 private:
  MsgObj m_res;
};

#define REGISTER_ASYNC_TASK(cmd, class, name) \
  static hsvr_base::HTaskRegister<cmd, class> class##_register_(name);
}  // namespace hsvr_base

#endif