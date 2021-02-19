#ifndef _HMYSQLCALLER_H
#define _HMYSQLCALLER_H
#include <vector>

#define MAXHCALLNUM 1000
namespace hsvr_base {

class HChannel;

class HCall {
 public:
  HCall() : m_taskid(0), m_callid(0), m_channel(NULL){};
  virtual ~HCall(){};
  void SetHCall(HChannel* channel, const char* sql);

 private:
  char m_sql[10240];
  uint32_t m_taskid;
  uint32_t m_callid;
  HChannel* m_channel;
};

class HCallMgr {
 public:
  HCallMgr();
  ~HCallMgr(){};

  int AddCall(HChannel* channel, const char* sql);

 private:
  typedef std::vector<HCall> HCALLVECTOR;
  HCALLVECTOR m_callvec;
  int m_write;
  int m_read;
};

class HMysqlCaller {
 public:
  HMysqlCaller(){};
  virtual ~HMysqlCaller(){};

  int AddCall(HChannel* channel, const char* sql);

 private:
  HCallMgr m_callmgr;
};

}  // namespace hsvr_base

#endif