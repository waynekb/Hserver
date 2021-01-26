#include "hkq.h"
#include <unistd.h>
#include "hchannelmgr.h"
#include "hlog/hlog.h"
#include "hsvr_base.h"

using namespace hsvr_base;
#define MAX_EVENTS_NUM 1024

int Hkq::Open_hkq() {
  if ((m_kq = kqueue()) < 0) {
    HLOG_ERR("create kqueue fail\n");
    return -1;
  }
  return 0;
}

int Hkq::Loop_hkq() {
  struct kevent events[MAX_EVENTS_NUM];
  int ev_num = kevent(m_kq, NULL, 0, events, MAX_EVENTS_NUM, NULL);
  HLOG_DEBUG("ev_num = %d\n", ev_num);
  for (int i = 0; i < ev_num; i++) {
    struct kevent event = events[i];
    int ready_fd = event.ident;
    HMonitChannelMgr* mgr = HMonitChannelMgr::GetInstance();
    mgr->Find(ready_fd)->HandleInput();
  }
  return ev_num;
}

void Hkq::Close_hkq() {
  if (m_kq > 0) {
    close(m_kq);
  }
  m_kq = 0;
}

int Hkq::Add_event(int fd, int16_t filter) {
  struct kevent ev;
  EV_SET(&ev, fd, filter, EV_ADD | EV_ENABLE | EV_CLEAR, 0, 0, NULL);
  return kevent(m_kq, &ev, 1, NULL, 0, NULL);
  /*
  if (filter == EVFILT_READ) {
    EV_SET(&ev, fd, filter, EV_ADD | EV_ENABLE, 0, 0, NULL);
  } else if (filter == EVFILT_WRITE) {
    EV_SET(&ev, fd, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
  } else {
    HLOG_WARN("filter is not EVFILT_READ or EVFILT_WRITE\n");
    return -1;
  }
  */
}

int Hkq::Del_event(int fd, int16_t filter) {
  struct kevent ev;
  if (filter == EVFILT_READ) {
    EV_SET(&ev, fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);
  } else if (filter == EVFILT_WRITE) {
    EV_SET(&ev, fd, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
  } else {
    HLOG_WARN("filter is not EVFILT_READ or EVFILT_WRITE\n");
    return -1;
  }
  return kevent(m_kq, &ev, 1, NULL, 0, NULL);
}