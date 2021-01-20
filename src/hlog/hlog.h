#ifndef HLOG_H
#define HLOG_H
#include <stdio.h>
#include <string>

using std::string;
class HlogMod {
 public:
  enum H_LEVEL {
    DEBUG = 0,
    INFO,
    WARN,
    ERROR,
  };
  HlogMod() : m_level(INFO), m_filename("") {
  }

  ~HlogMod();

  void Init_log(H_LEVEL level, string filename);

  void Print_log(H_LEVEL level, const char* fmt, ...);

 private:
  H_LEVEL m_level;
  string m_filename;
};

HlogMod* GetLogMod();

#define HLOG_DEBUG(fmt, ...)                                                                      \
  do {                                                                                            \
    GetLogMod()->Print_log(HlogMod::H_LEVEL::DEBUG, "[%s:%d][DEBUG\t]: " fmt, __FILE__, __LINE__, \
                           ##__VA_ARGS__);                                                        \
  } while (0)
;

#define HLOG_INFO(fmt, ...)                                                                     \
  do {                                                                                          \
    GetLogMod()->Print_log(HlogMod::H_LEVEL::INFO, "[%s:%d][INFO\t]: " fmt, __FILE__, __LINE__, \
                           ##__VA_ARGS__);                                                      \
  } while (0);

#define HLOG_WARN(fmt, ...)                                                                     \
  do {                                                                                          \
    GetLogMod()->Print_log(HlogMod::H_LEVEL::WARN, "[%s:%d][WARN\t]: " fmt, __FILE__, __LINE__, \
                           ##__VA_ARGS__);                                                      \
  } while (0);

#define HLOG_ERR(fmt, ...)                                                                        \
  do {                                                                                            \
    GetLogMod()->Print_log(HlogMod::H_LEVEL::ERROR, "[%s:%d][ERROR\t]: " fmt, __FILE__, __LINE__, \
                           ##__VA_ARGS__);                                                        \
  } while (0);

#endif