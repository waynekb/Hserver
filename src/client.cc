#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char** argv) {
  sockaddr_in cliaddr;
  cliaddr.sin_family = AF_INET;
  cliaddr.sin_port = htons(3260);
  cliaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  int clifd = socket(AF_INET, SOCK_STREAM, 0);
  if (clifd < 0) {
    printf("create svrfd fail!!!\n");
    return -1;
  }

  char buff[1024] = "ni hao ya dengqiyao!";
  int res = connect(clifd, (struct sockaddr*)&cliaddr, sizeof(struct sockaddr));
  printf("connect %d\n", res);
  if (res < 0) {
    perror("connect server fail:");
    return -1;
  }
  printf("strlen %ld\n", strlen(buff));
  res = send(clifd, buff, strlen(buff), 0);
  printf("send len %d\n", res);
  close(clifd);
  return 0;
}