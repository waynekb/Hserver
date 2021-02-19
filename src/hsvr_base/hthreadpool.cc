#include "hthreadpool.h"
#include "hlog/hlog.h"

using namespace hsvr_base;

int HThreadPool::Start(int num) {
  if (m_runflag == true) {
    HLOG_WARN("threadpool has been started\n");
    return 0;
  }
  m_runflag = true;
  for (int i = 0; i < num; i++) {
    m_threadvec.push_back(new std::thread(std::bind(&HThreadPool::ThreadProc, this)));
  }
  HLOG_INFO("ThreadPool start successful\n");
  return 0;
}

/*
int HThreadPool::ThreadLoop() {
  while (1) {
    if (!m_runflag) {
      break;
    }
  }
}
*/

int HThreadPool::Stop() {
  m_runflag = false;
  for (THREADVECTORIT it = m_threadvec.begin(); it != m_threadvec.end(); it++) {
    (*it)->join();
    delete *it;
  }
  m_threadvec.clear();
  HLOG_INFO("ThreadPool stop successful\n");
  return 0;
}