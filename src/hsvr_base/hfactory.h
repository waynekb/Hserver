#ifndef _HFACTORY_H
#define _HFACTORY_H
#include <map>
#include "common/hobject.h"
#include "hlog/hlog.h"

namespace hsvr_base {

class HTaskBase;

class HTaskCreator {
 public:
  virtual ~HTaskCreator(){};
  virtual HTaskBase* Create() = 0;
  virtual void Free(HTaskBase* task);
};

template <typename tasktype>
class HSimpleTaskCreator : public HTaskCreator {
 public:
  HTaskBase* Create() {
    return new tasktype;
  }
};

struct HTaskCreatorInfo {
  uint32_t cmd;
  const char* name;
  HTaskCreator* creator;

  HTaskCreatorInfo() {
    cmd = 0;
    name = NULL;
    creator = NULL;
  }
};

class HTaskFactory : public Singleton<HTaskFactory> {
 public:
  HTaskFactory(){};
  ~HTaskFactory() {
    ClearCreatorMap();
  };

  HTaskBase* CreateTask(uint32_t cmd);
  void ReleaseTask(HTaskBase* task);

  HTaskCreator* GetTaskCreator(uint32_t cmd);

  int RegisterCreator(HTaskCreatorInfo* info);

  int ReleaseCreator(uint32_t cmd);

  void ClearCreatorMap();

  typedef std::map<uint32_t, HTaskCreatorInfo*> HTASKCREATORINFOMAP;
  HTASKCREATORINFOMAP m_creatormap;

 private:
  uint32_t GenTaskId() {
    static uint32_t tid_seed = 0;
    return ++tid_seed;
  }

  uint32_t m_mincmd;
  uint32_t m_maxcmd;
};

template <uint32_t cmd, typename task>
class HTaskRegister {
 public:
  HTaskRegister(const char* name) {
    HTaskCreatorInfo* info = new HTaskCreatorInfo();
    info->cmd = cmd;
    info->name = name;
    info->creator = new HSimpleTaskCreator<task>;
    HTaskFactory::GetInstance()->RegisterCreator(info);
  }
};

}  // namespace hsvr_base

#endif