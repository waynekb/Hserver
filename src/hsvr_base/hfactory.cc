#include "hfactory.h"
#include "hlog/hlog.h"

using namespace hsvr_base;
using std::make_pair;

HTaskBase* HTaskFactory::CreateTask(uint32_t cmd) {
  HTaskCreator* creator = GetTaskCreator(cmd);
  if (creator == NULL) {
    return NULL;
  }
  HTaskBase* task = creator->Create();
  task->SetCmd(cmd);
  task->SetTaskId(GenTaskId());
  return task;
}

void HTaskFactory::ReleaseTask(HTaskBase* task) {
  delete task;
}

HTaskCreator* HTaskFactory::GetTaskCreator(uint32_t cmd) {
  if (cmd < m_mincmd || cmd > m_maxcmd) {
    HLOG_ERR("no creator cmd\n", cmd);
    return NULL;
  }
  HTASKCREATORINFOMAP::iterator it = m_creatormap.find(cmd);
  if (it == m_creatormap.end()) {
    HLOG_WARN("no creator cmd=%d\n", cmd);
    return NULL;
  }
  HTaskCreatorInfo* info = it->second;
  return info->creator;
}

int HTaskFactory::RegisterCreator(HTaskCreatorInfo* info) {
  uint32_t cmd = info->cmd;
  HTASKCREATORINFOMAP::iterator it = m_creatormap.find(cmd);
  if (it != m_creatormap.end()) {
    HLOG_ERR("cmd %d[%s] has been registered\n");
    return -1;
  }
  if (m_creatormap.size() == 0) {
    m_maxcmd = cmd;
    m_mincmd = cmd;
  }
  if (cmd > m_maxcmd) {
    m_maxcmd = cmd;
  }
  if (cmd < m_mincmd) {
    m_mincmd = cmd;
  }

  m_creatormap.insert(make_pair(cmd, info));
  return 0;
}

int HTaskFactory::ReleaseCreator(uint32_t cmd) {
  HTASKCREATORINFOMAP::iterator it = m_creatormap.find(cmd);
  if (it == m_creatormap.end()) {
    HLOG_WARN("cmd %d has not been registered\n");
    return 0;
  }
  HTaskCreatorInfo* info = it->second;
  delete info;
  m_creatormap.erase(cmd);
  return 0;
}

void HTaskFactory::ClearCreatorMap() {
  for (auto it = m_creatormap.begin(); it != m_creatormap.end(); it++) {
    HTaskCreatorInfo* info = it->second;
    delete info;
    m_creatormap.erase(it);
  }
}
