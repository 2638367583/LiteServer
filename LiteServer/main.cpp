/*
 * @Description: Test Lite Server
 * @Author: your name
 * @Date: 2019-05-19 12:28:18
 * @LastEditTime: 2019-05-20 01:08:09
 * @LastEditors: lileiyu
 */
#include <stdio.h>
#include "LTcpServer.h"
#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#endif

#include "LiteLog.h"
#define SERVER_PORT 18483

int main(int argc, char *argv[])
{
    //window要使用socket先初始化
#ifdef _WIN32
    WORD wVersionRequested;
    WSADATA wsaData;
    wVersionRequested = MAKEWORD(2, 2);
    WSAStartup(wVersionRequested, &wsaData);
#endif
    // SOCKET serverSocket = INVALID_SOCKET;
    // sockaddr_in serverAddr;
    // sockaddr_in clientAddr;
    // memset(&serverAddr, 0, sizeof(sockaddr_in));
    // memset(&clientAddr, 0, sizeof(clientAddr));
    // serverAddr.sin_family = AF_INET;
    // serverAddr.sin_addr.S_un.S_addr = htonl(ADDR_ANY);
    // serverAddr.sin_port = htons(SERVER_PORT);
    // //创建套接字
    // serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    // if (serverSocket == INVALID_SOCKET) {
    //     LiteLog::error("Failed to create socket.", 1);
    //     goto ERR_HANDLE;
    // }
    // //绑定套接字
    // if (bind(serverSocket, (sockaddr *)&serverAddr, sizeof(sockaddr)) < 0) {
    //     LiteLog::error("Failed to bind server.", 1);
    //     goto ERR_HANDLE;
    // }
    // //监听套接字
    // if (listen(serverSocket, 1024) < 0) {
    //     LiteLog::error("Failed to listen.", 1);
    //     goto ERR_HANDLE;
    // }
    // int addrInfoLen;
    // //等待连接
    // accept(serverSocket, (sockaddr *)&clientAddr, &addrInfoLen);
    // LiteLog::info("client connected.\n");
    // LiteLog::info("client network address is %d.", ntohl(clientAddr.sin_addr.S_un.S_addr));
    LTcpServer server(8888);
    sockaddr_in cli_addr = server.startServer();
    printf("[main] connect addr is %d\n", ntohl(cli_addr.sin_addr.s_addr));
    printf("[main] connect prot is %d\n", ntohs(cli_addr.sin_port));

ERR_HANDLE:
#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}
