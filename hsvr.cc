#include "hsvr.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "hlog/hlog.h"

using namespace happ;

int HappSvr::OnUpdate() {
  int nev = 0;
  HLOG_DEBUG("nev %d\n", nev);
  nev = kevent(m_kq, NULL, 0, m_events, 1024, NULL);
  HLOG_DEBUG("nev %d\n", nev);
  for (int i = 0; i < nev; i++) {
    struct kevent event = m_events[i];
    int ready_fd = *((int *)event.udata);
    if (ready_fd == m_svrfd) {
      sockaddr_in cli_addr;
      int cli_addrlen = sizeof(cli_addr);
      int cli_fd = accept(m_svrfd, (sockaddr *)&cli_addr, (socklen_t *)&cli_addrlen);
      if (cli_fd < 0) {
        HLOG_ERR("accept new connect fail\n");
        continue;
      }
      EV_SET(&m_lis_event[m_num++], cli_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
      kevent(m_kq, m_lis_event, m_num, NULL, 0, NULL);
    } else {
      if (event.filter == EVFILT_READ) {
        int nread = recv(ready_fd, m_buff, sizeof(m_buff), 0);
        if (nread < 0) {
          HLOG_ERR("read socket fail\n");
        }
        HLOG_INFO("recv msg:%s\n", m_buff);
      } else if (event.filter == EVFILT_WRITE) {
        HLOG_INFO("please input\n");
      }
    }
  }
  return 0;
}

int HappSvr::Svrrun() {
  HLOG_DEBUG("\n");
  sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(3260);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  int fd = socket(AF_INET, SOCK_STREAM, 0);
  printf("fd:%d\n", fd);
  bind(fd, (sockaddr *)&addr, sizeof(struct sockaddr));
  int res = listen(fd, 100);
  printf("listen res:%d\n", res);
  socklen_t len = 0;
  int clifd = accept(fd, (sockaddr *)&addr, &len);
  char buff[1024] = {0};
  recv(clifd, buff, 1024, 0);
  printf("recv msg:%s\n", buff);
  return 0;
}

int HappSvr::OnTest() {
  sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(3260);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  int fd = socket(AF_INET, SOCK_STREAM, 0);
  printf("fd:%d\n", fd);
  bind(fd, (sockaddr *)&addr, sizeof(struct sockaddr));
  int res = listen(fd, 100);
  printf("listen res:%d\n", res);
  socklen_t len = 0;
  int clifd = accept(fd, (sockaddr *)&addr, &len);
  char buff[1024] = {0};
  recv(clifd, buff, 1024, 0);
  printf("recv msg:%s\n", buff);
  return 0;
}

int HappSvr::OnInit() {
  sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(3260);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  int fd = socket(AF_INET, SOCK_STREAM, 0);
  printf("fd:%d\n", fd);
  bind(fd, (sockaddr *)&addr, sizeof(struct sockaddr));
  int res = listen(fd, 100);
  printf("listen res:%d\n", res);
  socklen_t len = 0;
  int clifd = accept(fd, (sockaddr *)&addr, &len);
  char buff[1024] = {0};
  recv(clifd, buff, 1024, 0);
  printf("recv msg:%s\n", buff);
  return 0;
}

/*
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

  socklen_t len = 0;
  HLOG_DEBUG("\n");
  int clifd = accept(m_svrfd, (sockaddr *)&sock, &len);
  char buff[1024] = {0};
  recv(clifd, buff, 1024, 0);
  HLOG_DEBUG("recv msg:%s", buff);
  exit(1);

  m_kq = kqueue();
  if (m_kq < 0) {
    HLOG_ERR("Create kqueue fail\n");
    return -1;
  }

  EV_SET(&m_lis_event[m_num++], m_svrfd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
  int res = kevent(m_kq, m_lis_event, m_num, NULL, 0, NULL);
  if (res < 0) {
    HLOG_ERR("add server fd to kq fail\n");
    return -1;
  }
  HLOG_INFO("Init Server successful!!!\n");
  return 0;
}
*/