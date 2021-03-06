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

using namespace std;

class LTcpServer
{
public:
    explicit LTcpServer(short port);
    ~LTcpServer();
    sockaddr_in startServer();
protected:
    void initServer();
    void create();
    void bind();
    void listen();

private:
    short m_port; //使用的端口号
    std::string m_addr;   //绑定的ip地址
    sockaddr_in m_sockaddrin;
    int m_sSocket;     //服务器socket
};