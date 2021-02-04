#include "hchannelmgr.h"

using namespace hsvr_base;
using std::make_pair;

int HMonitChannelMgr::Add(int fd, HChannel* channel) {
  m_map.insert(make_pair(fd, channel));
  return 0;
}

int HMonitChannelMgr::Del(int fd) {
  m_map.erase(fd);
  return 0;
}
HChannel* HMonitChannelMgr::Find(int fd) {
  ChannleMapIt it = m_map.find(fd);
  return it->second;
}

HChannel* HChannelPool::GetNewChannel() {
  if (m_freelist.size() <= 0) {
    return NULL;
  }
  HChannel* ch = m_freelist.front();
  m_freelist.pop_front();
  return ch;
}

void HChannelPool::AddFreeChannel(HChannel* channel) {
  m_freelist.push_back(channel);
}
int HChannelPool::GetFreeChannelNum() {
  return m_freelist.size();
}

void HTcpChannelPool::InitPool() {
  for (int i = 0; i < MAX_CHANNEL_NUM; i++) {
    AddFreeChannel((HChannel*)&m_arry[i]);
  }
}
