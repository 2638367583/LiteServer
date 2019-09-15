
#include "LTcpServer.h"

LTcpServer::LTcpServer(short port):m_port(port)
{
    m_sockaddrin.sin_family = AF_INET;
    m_sockaddrin.sin_port = htons(m_port);
    m_sockaddrin.sin_addr.s_addr = htonl(INADDR_ANY);
}

LTcpServer::~LTcpServer()
{
}

void LTcpServer::create()
{
    //原型 int socket(domain, type, protocol)
    //  domain：即协议域，又称为协议族（family）。常用的协议族有，AF_INET、AF_INET6、AF_LOCAL
    //或称AF_UNIX，Unix域socket）、AF_ROUTE等等。协议族决定了socket的地址类型，在通信中必须采用对应的地址，
    //如AF_INET决定了要用ipv4地址（32位的）与端口号（16位的）的组合、AF_UNIX决定了要用一个绝对路径名作为地址。
    //  type：指定socket类型。常用的socket类型有，SOCK_STREAM、SOCK_DGRAM、SOCK_RAW、SOCK_PACKET、SOCK_SEQPACKET等等
    //  protocol：故名思意，就是指定协议。常用的协议有，IPPROTO_TCP、IPPTOTO_UDP、IPPROTO_SCTP、IPPROTO_TIPC等，
    //它们分别对应TCP传输协议、UDP传输协议、STCP传输协议、TIPC传输协议
    m_sSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_sSocket < 0) {
        fprintf(stderr, "[create] Failed to create socket.");
        exit(1);
    }
}

void LTcpServer::bind()
{
    //原型i nt bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    //sockfd：即socket描述字，它是通过socket()函数创建了，唯一标识一个socket。bind()函数就是将给这个描述字绑定一个名字。
    //addr：一个const struct sockaddr *指针，指向要绑定给sockfd的协议地址。这个地址结构根据地址创建socket时的地址协议族的不同而不同，如ipv4对应的是： 
    //struct sockaddr_in {
    //sa_family_t    sin_family; /* address family: AF_INET */
    //in_port_t      sin_port;   /* port in network byte order */
    //struct in_addr sin_addr;   /* internet address */
    //};
    //struct in_addr {
    //uint32_t       s_addr;     /* address in network byte order */
    //};
    
    int ret = ::bind(m_sSocket, (sockaddr* )&m_sockaddrin, sizeof(m_sockaddrin));
    if (ret < 0) {
        fprintf(stderr, "[bind] Faied to bind.");
        exit(1);
    }
}

void LTcpServer::listen()
{
    /*
    原型int listen(int sockfd, int backlog);
    sockfd:要监听的socket描述字，
    backlog: 为相应socket可以排队的最大连接个数。
    socket()函数创建的socket默认是一个主动类型的，listen函数将socket变为被动类型的，等待客户的连接请求。
    */
    int ret = ::listen(m_sSocket, 1024);
    if (ret < 0) {
        fprintf(stderr, "[listen] Failed to listen.");
        exit(1);
    }
}

void LTcpServer::initServer()
{
    create();
    bind();
    listen();
}

sockaddr_in LTcpServer::startServer()
{
    initServer();
    //int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    //accept函数的第一个参数为服务器的socket描述字，第二个参数为指向struct sockaddr *的指针，用于返回客户端的协议地址，
    //第三个参数为协议地址的长度。如果accpet成功，那么其返回值是由内核自动生成的一个全新的描述字，代表与返回客户的TCP连接。
    //注意：accept的第一个参数为服务器的socket描述字，是服务器开始调用socket()函数生成的，称为监听socket描述字；
    //而accept函数返回的是已连接的socket描述字。一个服务器通常通常仅仅只创建一个监听socket描述字，它在该服务器的生命周期内一直存在。
    //内核为每个由服务器进程接受的客户连接创建了一个已连接socket描述字，当服务器完成了对某个客户的服务，相应的已连接socket描述字就被关闭。
    sockaddr_in addr;
    socklen_t len;
    int ret = ::accept(m_sSocket, (sockaddr *)&addr, &len);
    if (ret < 0) {
        fprintf(stderr, "[startServer] accept socket error: %s(errno: %d)", strerror(errno), errno);
        // return NULL;
    }
    return addr;
}