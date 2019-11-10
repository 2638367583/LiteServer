//
// Created by 李雷雨 on 2019/10/20.
//

#include "LUdpServer.h"

LUdpServer::LUdpServer(short port) {

}

LUdpServer::~LUdpServer() {

}

LUdpServer::LUdpServer() {}

bool LUdpServer::create()
{
    //原型 int socket(domain, type, protocol)
    //  domain：即协议域，又称为协议族（family）。常用的协议族有，AF_INET、AF_INET6、AF_LOCAL
    //或称AF_UNIX，Unix域socket）、AF_ROUTE等等。协议族决定了socket的地址类型，在通信中必须采用对应的地址，
    //如AF_INET决定了要用ipv4地址（32位的）与端口号（16位的）的组合、AF_UNIX决定了要用一个绝对路径名作为地址。
    //  type：指定socket类型。常用的socket类型有，SOCK_STREAM、SOCK_DGRAM、SOCK_RAW、SOCK_PACKET、SOCK_SEQPACKET等等
    //  protocol：故名思意，就是指定协议。常用的协议有，IPPROTO_TCP、IPPTOTO_UDP、IPPROTO_SCTP、IPPROTO_TIPC等，
    //它们分别对应TCP传输协议、UDP传输协议、STCP传输协议、TIPC传输协议
    m_sSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (m_sSocket < 0) {
        fprintf(stderr, "[create] Failed to create socket.");
        exit(1);
    }
}

bool LUdpServer::bind() {
    int ret = ::bind(m_sSocket, (sockaddr* )&m_sockaddrin, sizeof(m_sockaddrin));
    if (ret < 0) {
        fprintf(stderr, "[bind] Faied to bind.");
        exit(1);
    }
    return true;
}

bool LUdpServer::receive() {
//    recvfrom()
    return false;
}


