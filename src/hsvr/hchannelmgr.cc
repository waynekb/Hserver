#include "hchannelmgr.h"

using namespace hsvr;
using std::make_pair;

int HMonitChannelMgr::Add(int fd, Channel* channel) {
  m_map.insert(make_pair(fd, channel));
  return 0;
}

int HMonitChannelMgr::Del(int fd) {
  m_map.erase(fd);
  return 0;
}
Channel* HMonitChannelMgr::Find(int fd) {
  ChannleMapIt it = m_map.find(fd);
  return it->second;
}

Channel* HChannelPool::GetNewChannel() {
  if (m_list.size() <= 0) {
    return NULL;
  }
  Channel* ch = m_list.front();
  m_list.pop_front();
  return ch;
}

void HChannelPool::AddChannel(Channel* channel) {
  m_list.push_back(channel);
}

void HTcpChannelPool::InitPool() {
  for (int i = 0; i < MAX_CHANNEL_NUM; i++) {
    AddChannel((Channel*)&m_arry[i]);
  }
}
