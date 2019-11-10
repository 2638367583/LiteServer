cmake_minimum_required(VERSION 3.10)
project(LiteServer)

set(CMAKE_CXX_STANDARD 11)

include_directories(LiteServer)

add_executable(LiteServer
        LiteServer/LiteLog.cpp
        LiteServer/LiteLog.h
        LiteServer/LTcpServer.cpp
        LiteServer/LTcpServer.h
        LiteServer/main.cpp LiteServer/LUdpServer.cpp LiteServer/LUdpServer.h)
