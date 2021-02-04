#ifndef _HDATASTRUCT_H
#define _HDATASTRUCT_H

struct ReqContext {
  unsigned int cmd;
  unsigned int seq_no;

  ReqContext() {
    cmd = 0;
    seq_no = 0;
  }
};

#endif