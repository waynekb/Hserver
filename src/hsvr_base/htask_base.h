#ifndef _HTASK_BASE_H
#define _HTASK_BASE_H

namespace hsvr_base {
class HTaskBase {
 public:
  HTaskBase() {
  }
  virtual ~HTaskBase() {
  }

  virtual int Start(const void* msg) {
    return 0;
  };

 private:
};
}  // namespace hsvr_base

#endif