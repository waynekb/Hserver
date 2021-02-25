#include "hthreadpool.h"
#include "hlog/hlog.h"

using namespace hsvr_base;

int HThreadPoolBase::Start(int num) {
  if (m_runflag == true) {
    HLOG_WARN("threadpool has been started\n");
    return 0;
  }
  m_runflag = true;
  for (int i = 0; i < num; i++) {
    m_threadvec.push_back(new std::thread(std::bind(&HThreadPoolBase::ThreadProc, this, i)));
  }
  HLOG_INFO("ThreadPool start successful\n");
  return 0;
}

int HThreadPoolBase::Stop() {
  m_runflag = false;
  for (THREADVECTORIT it = m_threadvec.begin(); it != m_threadvec.end(); it++) {
    (*it)->join();
    delete *it;
  }
  m_threadvec.clear();
  HLOG_INFO("ThreadPool stop successful\n");
  return 0;
}

HLoopThreadPool::~HLoopThreadPool() {
  if (!m_freelist.empty()) {
    m_freelist.clear();
  }
  if (!m_eventlist.empty()) {
    m_eventlist.clear();
  }
}

void HLoopThreadPool::InitPushFreeList(void* event) {
  m_freelist.push_back(event);
}

void HLoopThreadPool::PushFreeList(void* event) {
  std::unique_lock<std::mutex> lock(m_freemtx);
  m_freelist.push_back(event);
}

void HLoopThreadPool::AddEvent(void* event) {
  {
    std::unique_lock<std::mutex> lock(m_eventmtx);
    m_eventlist.push_back(event);
  }
  m_con.notify_all();
}

void* HLoopThreadPool::GetFreeBox() {
  if (m_freelist.empty()) {
    HLOG_WARN("event is full, please wait !!\n");
    return NULL;
  }
  std::unique_lock<std::mutex> lock(m_freemtx);
  void* event = NULL;
  event = m_freelist.front();
  m_freelist.pop_front();
  return event;
}

int HLoopThreadPool::GetThreadid() {
  return m_threadid;
}

void* HLoopThreadPool::GetEvent() {
  std::unique_lock<std::mutex> lock(m_eventmtx);
  while (m_runflag && m_eventlist.empty()) {
    m_con.wait(lock);
  }
  void* event = NULL;
  if (m_runflag && !m_eventlist.empty()) {
    event = m_eventlist.front();
    m_eventlist.pop_front();
  }
  return event;
}

/*
 * 通过使用代码块，释放锁。否则在poolbase的stop()函数中，唤醒的进程无法获取锁，会阻塞。
 * 而主线程却又要等待线程join，才会释放锁。
 */
int HLoopThreadPool::Stop() {
  {
    std::unique_lock<std::mutex> lock(m_eventmtx);
    m_runflag = false;
    m_con.notify_all();
  }  //必须使用代码块，否则会出现死锁。
  HThreadPoolBase::Stop();
  return 0;
}

int HLoopThreadPool::ThreadProc(int id) {
  while (m_runflag) {
    m_threadid = id;
    pthread_t tid;
    tid = pthread_self();

    void* event = GetEvent();
    if (event) {
      DoEvent(event);
    }
  }
  return 0;
}
