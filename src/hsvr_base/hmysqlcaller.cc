#include "hmysqlcaller.h"
#include "hchannel.h"
#include "hlog/hlog.h"

using namespace hsvr_base;

void HCall::SetHCall(HChannel* channel, const char* sql) {
  memcpy(m_sql, sql, strlen(sql));
  m_channel = channel;
}

HCallMgr::HCallMgr() {
  m_callvec.reserve(MAXHCALLNUM);
  m_write = 0;
  m_read = 0;
}

int HCallMgr::AddCall(HChannel* channel, const char* sql) {
  if ((m_write + 1) % MAXHCALLNUM == m_read) {
    HLOG_DEBUG("call vector full\n");
    return -1;
  }
  m_callvec[m_write].SetHCall(channel, sql);
  m_write++;
  return 0;
}

int HMysqlCaller::AddCall(HChannel* channel, const char* sql) {
  return m_callmgr.AddCall(channel, sql);
}