#ifndef _HTHREADPOOL_H
#define _HTHREADPOOL_H
#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>
#include "common/hobject.h"

namespace hsvr_base {
/*
 * 线程池就是创建线程，执行线程，并且销毁线程，至于线程执行的函数是什么
 * 至于执行函数是循环还是还是一次执行函数，都应该由开发者决定。
 */

class HThreadPool {
 public:
  HThreadPool() : m_runflag(false){};
  ~HThreadPool(){};

  int Start(int num);
  int Stop();
  virtual int ThreadProc() = 0;

 private:
  // int ThreadLoop();

  typedef std::vector<std::thread*> THREADVECTOR;
  typedef THREADVECTOR::iterator THREADVECTORIT;

  THREADVECTOR m_threadvec;
  bool m_runflag;
  std::mutex m_mtx;
  std::condition_variable m_con;
};
}  // namespace hsvr_base

#endif