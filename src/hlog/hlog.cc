#include "hlog.h"
#include <fstream>
#include <iostream>

#include <time.h>
using namespace std;

void HlogMod::Init_log(H_LEVEL level, string filename) {
  m_level = level;
  m_filename = filename;
  return;
}

void HlogMod::Print_log(H_LEVEL level, const char* fmt, ...) {
  if (level < m_level) {
    return;
  }

  if (m_filename == "") {
    printf("please set logfile \n");
    abort();
  }

  ofstream fs;
  fs.open(m_filename, ios::app);
  if (!fs.is_open()) {
    printf("Open file %s fail!!!\n", m_filename.c_str());
    return;
  }

  va_list ap;
  va_start(ap, fmt);
  char log_msg[1024] = {0};
  vsnprintf(log_msg, sizeof(log_msg), fmt, ap);
  va_end(ap);

  string str_log = log_msg;
  size_t pos = str_log.find("src") + 4;
  str_log = "[" + str_log.substr(pos);

  time_t now = time(NULL);
  char timestr[20] = {0};
  strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", localtime(&now));

  fs << timestr << str_log;

  fs.close();
  return;
}

static HlogMod* hlog_ins = nullptr;

HlogMod::~HlogMod() {
  if (hlog_ins != nullptr) {
    hlog_ins = nullptr;
  }
  return;
}

HlogMod* GetLogMod() {
  if (hlog_ins == nullptr) {
    static HlogMod ConsLogMod;
    hlog_ins = &ConsLogMod;
  }
  return hlog_ins;
}