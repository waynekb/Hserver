#ifndef _HCHANNELMGR_H
#define _HCHANNELMGR_H

#include <list>
#include <map>
#include "common/hobject.h"
#include "htcpchannel.h"

#define MAX_CHANNEL_NUM 1000

namespace hsvr_base {

class HMonitChannelMgr : public Singleton<HMonitChannelMgr> {
 public:
  HMonitChannelMgr() {
  }
  ~HMonitChannelMgr() {
  }

  int Add(int fd, HChannel* channel);
  int Del(int fd);
  HChannel* Find(int fd);

 private:
  typedef std::map<int, HChannel*> ChannelMap;
  typedef ChannelMap::iterator ChannleMapIt;
  ChannelMap m_map;
};

class HChannelPool {
 public:
  HChannelPool() {
  }
  ~HChannelPool() {
  }

  HChannel* GetNewChannel();
  void AddChannel(HChannel* channel);

 private:
  typedef std::list<HChannel*> ChannelList;

  ChannelList m_list;
};

class HTcpChannelPool : public Singleton<HTcpChannelPool>, public HChannelPool {
 public:
  HTcpChannelPool() {
  }
  ~HTcpChannelPool() {
  }

  void InitPool();

 private:
  HTcpChannel m_arry[MAX_CHANNEL_NUM];
};
}  // namespace hsvr_base

#endif