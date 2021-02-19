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

# 添加子目录
add_subdirectory(hlog)
add_subdirectory(happ)
add_subdirectory(hsvr_base)
add_subdirectory(hmessage)
#add_subdirectory(common)

#添加头文件目录 相当于 -I
include_directories(${CMAKE_SOURCE_DIR})
include_directories(/user/local/mysql/include/)
include_directories(/usr/local/include/)

#添加链接库查询目录 相当于-L
link_directories(/usr/local/protobuf/lib)
link_directories(/usr/local/mysql/lib)
# 指定生成目标
add_executable(hserver main.cc)

# 添加链接库

target_link_libraries(hserver LogMod HappMod HsvrMod MsgMod protobuf mysqlclient)
#target_link_libraries(hserver MsgMod protobuf)

add_executable(hclient client.cc)
#add_executable(htest server.cc)
target_link_libraries(hclient LogMod MsgMod protobuf)
