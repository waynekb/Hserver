#include "hsvr.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "hlog/hlog.h"

using namespace happ;

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