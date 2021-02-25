#ifndef _HThreadPoolBase_H
#define _HThreadPoolBase_H
#include <condition_variable>
#include <list>
#include <mutex>
#include <thread>
#include <vector>
#include "common/hobject.h"
#include "mysql/mysql.h"

namespace hsvr_base {
/*
 * 线程池就是创建线程，执行线程，并且销毁线程，至于线程执行的函数是什么
 * 至于执行函数是循环还是还是一次执行函数，都应该由开发者决定。
 * poolbase是最最基础的线程池，没有锁，不循环。loopthreadpool线程从队列
 * 获取任务，所以是加了锁的，于是需要隐藏base类的stop()
 */

class HThreadPoolBase {
 public:
  HThreadPoolBase() : m_runflag(false){};
  ~HThreadPoolBase(){};

  int Start(int num);
  int Stop();

  virtual int ThreadProc(int act) = 0;

 protected:
  bool m_runflag;

 private:
  // int ThreadLoop();

  typedef std::vector<std::thread*> THREADVECTOR;
  typedef THREADVECTOR::iterator THREADVECTORIT;

  THREADVECTOR m_threadvec;
};

static thread_local int m_threadid;
class HLoopThreadPool : public HThreadPoolBase {
 public:
  HLoopThreadPool() : HThreadPoolBase(){};
  virtual ~HLoopThreadPool();
  virtual int DoEvent(void* event) {
    return 0;
  };
  void InitPushFreeList(void* event);
  void PushFreeList(void* event);
  void AddEvent(void* event);
  void* GetFreeBox();
  void* GetEvent();

  int Stop();
  int GetThreadid();
  /**
   * 因为不知道上层类的任务会是什么格式，所以当前任务列表保存的是指针。
   * 派生类创建任务结构，再将指针传入任务列表。
   */
  std::list<void*> m_freelist;  //空闲列表，添加任务时，从该列表获取存储任务的对象
  std::list<void*> m_eventlist;  //任务列表，线程从该列表获取任务。

 private:
  virtual int ThreadProc(int act);

  std::mutex m_freemtx;
  std::mutex m_eventmtx;
  std::condition_variable m_con;
};

}  // namespace hsvr_base

#endif