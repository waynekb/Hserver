#include "htaskmgr.h"
#include "hfactory.h"
#include "hlog/hlog.h"

using std::make_pair;
using namespace hsvr_base;

HTaskBase* HTaskMgr::GetTask(uint32_t taskid) {
  HTASKBASEMAPIT it = m_taskmap.find(taskid);
  if (it == m_taskmap.end()) {
    return NULL;
  }
  return it->second;
}

int HTaskMgr::PendTask(HTaskBase* task) {
  uint32_t taskid = task->GetTaskId();
  HTASKBASEMAPIT it = m_taskmap.find(taskid);
  if (it != m_taskmap.end()) {
    HLOG_WARN("taskid=%d exist\n");
    return -1;
  }
  m_taskmap.insert(make_pair(taskid, task));
  return 0;
}

void HTaskMgr::ReleaseAllTask() {
  if (GetTaskNum() == 0) {
    return;
  }
  for (auto it = m_taskmap.begin(); it != m_taskmap.end(); it++) {
    m_taskmap.erase(it);
    HTaskFactory::GetInstance()->ReleaseTask(it->second);
  }
}

void HTaskMgr::ReleaseTask(uint32_t taskid) {
  HTASKBASEMAPIT it = m_taskmap.find(taskid);
  if (it != m_taskmap.end()) {
    return;
  }
  m_taskmap.erase(it);
  HTaskFactory::GetInstance()->ReleaseTask(it->second);
  return;
}

uint32_t HTaskMgr::GetTaskNum() {
  return m_taskmap.size();
}