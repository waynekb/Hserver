# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)
#添加头文件
include_directories(/usr/local/include/)
include_directories(${CMAKE_SOURCE_DIR})
# 生成链接库
add_library (MsgMod ${DIR_LIB_SRCS})
