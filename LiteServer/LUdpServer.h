//
// Created by 李雷雨 on 2019/10/20.
//

#ifndef LITESERVER_LUDPSERVER_H
#define LITESERVER_LUDPSERVER_H
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class LUdpServer {
public:
    explicit LUdpServer(short port);
    LUdpServer();
    virtual ~LUdpServer();

    bool create();
    bool bind();
    bool receive();

private:
    short m_port; //使用的端口号
    std::string m_addr;   //绑定的ip地址
    sockaddr_in m_sockaddrin;
    int m_sSocket;
};


#endif //LITESERVER_LUDPSERVER_H
