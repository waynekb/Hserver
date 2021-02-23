#ifndef _HTASKMGR_H
#define _HTASKMGR_H
#include <map>
#include <queue>
#include <set>
#include "common/hobject.h"
#include "htask_base.h"

namespace hsvr_base {

class HTaskMgr : public Singleton<HTaskMgr> {
 public:
  HTaskBase* FindTask(uint32_t taskid);

  int PendTask(HTaskBase* task);
  void ReleaseTask(uint32_t taskid);

  void ReleaseAllTask();
  uint32_t GetTaskNum();

  void InsertTaskToSet(uint32_t taskid);

  int IsTaskComplete();

 private:
  typedef std::map<uint32_t, HTaskBase*> HTASKBASEMAP;
  typedef HTASKBASEMAP::iterator HTASKBASEMAPIT;

  std::set<uint32_t> m_taskset;
  HTASKBASEMAP m_taskmap;
};
}  // namespace hsvr_base

#endif