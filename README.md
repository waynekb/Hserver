[toc]

# Hserver
HUWEI SERVER

# hlog 日志模块
日志是所有程序的基础，hlog日志是一个独立单例模块，开发者只需要在程序开端初始化时指定日志写入路径，即可使用日志模块，非常便捷。
```
void Init_log(H_LEVEL level, string filename);
level：日志输出的最低等级，分别是DEBUG,INFO,WARN,ERROR
filename：日志文件路径
```
```
#include "hlog.h"
GetLogMod()->Init_log(HlogMod::H_LEVEL::DEBUG,
                        "/Users/waynebfhu/Documents/study/H3_server/logs/hsvr_log.log");
```

# happ 模块
通常服务器都是重复接收前端发送的请求，并作出响应，所以happ必然是一个无限循环的执行某个函数。该模块提供了

