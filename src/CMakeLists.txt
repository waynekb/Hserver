#CMake最低版本号要求
cmake_minimum_required(VERSION 2.8)

#项目信息
project(wayne)

#指定c++17标准
set(CMAKE_CXX_STANDARD 17)

#设置gdb
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# 查找当前目录下的所有源文件,并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加子目录
add_subdirectory(hlog)
add_subdirectory(happ)
add_subdirectory(hsvr_base)
add_subdirectory(proto/proto)
#add_subdirectory(common)

# 指定生成目标
add_executable(hserver main.cc)

#添加头文件目录 相当于 -I
include_directories(${CMAKE_SOURCE_DIR})
include_directories(/usr/local/include/)

# 添加链接库
target_link_libraries(hserver LogMod HappMod HsvrMod)

add_executable(hclient client.cc)
#add_executable(htest server.cc)
#target_link_libraries(htest LogMod HappMod)
