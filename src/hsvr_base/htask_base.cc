#include "htask_base.h"

using namespace hsvr_base;

void HTaskBase::SetCmd(uint32_t cmd) {
  m_cmd = cmd;
}

uint32_t HTaskBase::GetCmd() {
  return m_cmd;
}

void HTaskBase::SetTaskId(uint32_t taskid) {
  m_taskid = taskid;
}
uint32_t HTaskBase::GetTaskId() {
  return m_taskid;
}