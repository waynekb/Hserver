#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <sys/socket.h>
#include <unistd.h>
#include "hmessage/hmessage.pb.h"

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

  int res = connect(clifd, (struct sockaddr*)&cliaddr, sizeof(struct sockaddr));
  printf("connect %d\n", res);
  if (res < 0) {
    perror("connect server fail:");
    return -1;
  }

  HPR_SvrMsg msg;
  HPR_MsgHead* head = msg.mutable_head();
  HPR_GetStudentInfoReq* body = msg.mutable_body()->mutable_get_student_info_req();
  head->set_cmd(1);
  head->set_seqno(100001);

  body->add_roleids(1);
  body->add_roleids(2);
  body->add_roleids(3);
  char buff[1024] = {0};
  msg.SerializeToArray((void*)buff, 1024);

  msg.mutable_head()->CopyFrom(msg.head());

  for (int i = 0; i < 3; i++) {
    res = send(clifd, buff, strlen(buff), 0);
    printf("send len %d\n", res);
    printf("\n*******************************\n");
    char recvbuf[1024];
    res = recv(clifd, recvbuf, 1024, 0);
    printf("res = %d\n", res);
    if (res <= 0) {
      return 0;
    }

    msg.ParseFromArray(recvbuf, res);

    const HPR_GetStudentInfoRes& info = msg.body().get_student_info_res();
    if (info.err_code() != 0) {
      printf("GetStudentInfo fail\n");
      return 0;
    }
    for (int i = 0; i < info.students_size(); i++) {
      const HPR_StudentInfo& student = info.students(i);
      printf("student:%d name:%s age=%d grade=%d sub_date:%s\n", student.roleid(),
             student.name().c_str(), student.age(), student.grade(), student.date().c_str());
    }
    sleep(1);
  }

  close(clifd);
  return 0;
}