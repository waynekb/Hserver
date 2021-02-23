#ifndef _HASYNCTASK_H
#define _HASYNCTASK_H
/**
 * 异步任务基类
 */
namespace hsvr_base {

class HAsyncTaskbase {
 public:
  virtual int DoResponse() = 0;
};

class HMysqlCallbackBase {
 public:
  bool virtual CallbackIsComplete() = 0;
};
}  // namespace hsvr_base

#endif