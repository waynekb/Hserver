#ifndef _HTASKMGR_H
#define _HTASKMGR_H
#include <map>
#include "common/hobject.h"
#include "htask_base.h"

namespace hsvr_base {

class HTaskMgr : public Singleton<HTaskMgr> {
 public:
  HTaskBase* GetTask(uint32_t taskid);

  int PendTask(HTaskBase* task);
  void ReleaseTask(uint32_t taskid);

  void ReleaseAllTask();
  uint32_t GetTaskNum();

 private:
  typedef std::map<uint32_t, HTaskBase*> HTASKBASEMAP;
  typedef HTASKBASEMAP::iterator HTASKBASEMAPIT;

  HTASKBASEMAP m_taskmap;
};
}  // namespace hsvr_base

#endif