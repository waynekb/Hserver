#include "hsvr.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "hlog/hlog.h"

using namespace happ;

int HappSvr::OnUpdate() {
  int nev = 0;
  struct kevent events[1024];
  nev = kevent(m_kq, NULL, 0, events, sizeof(events), NULL);
  for (int i = 0; i < nev; i++) {
    struct kevent event = events[i];
    int ready_fd = event.ident;
    if (ready_fd == m_svrfd) {
      sockaddr_in cli_addr;
      int cli_addrlen = sizeof(cli_addr);
      int cli_fd = accept(m_svrfd, (sockaddr *)&cli_addr, (socklen_t *)&cli_addrlen);
      HLOG_DEBUG("new connect fd:%d\n", cli_fd);
      if (cli_fd < 0) {
        HLOG_ERR("accept new connect fail\n");
        continue;
      }
      Add_moni_event(cli_fd);
    } else {
      if (event.filter == EVFILT_READ) {
        char buff[1024] = {0};
        int nread = recv(ready_fd, buff, sizeof(buff), 0);
        HLOG_DEBUG("nread = %d\n", nread);
        if (nread < 0) {
          HLOG_ERR("read socket fail\n");
        } else if (nread == 0) {
          Del_moni_event(ready_fd);
        } else {
          HLOG_INFO("recv msg:%s\n", buff);
        }
      } else if (event.filter == EVFILT_WRITE) {
        HLOG_INFO("please input\n");
      }
    }
  }
  return 0;
}

int HappSvr::OnInit() {
  sockaddr_in sock;
  sock.sin_family = AF_INET;
  sock.sin_port = htons(3260);
  sock.sin_addr.s_addr = inet_addr("127.0.0.1");

  m_svrfd = socket(AF_INET, SOCK_STREAM, 0);
  if (m_svrfd < 0) {
    HLOG_ERR("create svrfd fail!!!\n");
    return -1;
  }
  HLOG_DEBUG("fd:%d\n", m_svrfd);
  bind(m_svrfd, (sockaddr *)&sock, sizeof(struct sockaddr));
  if (listen(m_svrfd, 100) < 0) {
    HLOG_ERR("listen socket failed\n");
    return -1;
  }

  m_kq = kqueue();
  if (m_kq < 0) {
    HLOG_ERR("Create kqueue fail\n");
    return -1;
  }
  if (Add_moni_event(m_svrfd) < 0) {
    HLOG_ERR("kqueue add listen socket fail\n");
    abort();
  }
  HLOG_INFO("Init Server successful!!!\n");
  return 0;
}

int HappSvr::Add_moni_event(int fd) {
  struct kevent ev;
  EV_SET(&ev, fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
  return kevent(m_kq, &ev, 1, NULL, 0, NULL);
}

int HappSvr::Del_moni_event(int fd) {
  struct kevent ev;
  EV_SET(&ev, fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);
  return kevent(m_kq, &ev, 1, NULL, 0, NULL);
}
