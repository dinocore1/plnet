
#include <arpa/inet.h>
#include "Socket.h"

namespace plnet
{
    INetAddress::INetAddress(const string& addrStr, uint16_t port)
    {
        inet_pton(AF_INET, addrStr.c_str(), &ipv4addr);
        this->port = port;
    }

    int Socket::create(int af, int type, Socket* socket)
    {
        int ret;
        ret = socket->udtSocket = UDT::socket(af, type, 0);
        return ret;
    }

    int Socket::bind(const INetAddress& addr)
    {
        sockaddr_in my_addr;
        my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(addr.port);
        my_addr.sin_addr.s_addr = addr.ipv4addr;
    
        return UDT::bind(udtSocket, (sockaddr*)&my_addr, sizeof(my_addr));
    }

    int Socket::listen(int backlog)
    {
        return UDT::listen(udtSocket, backlog);
    }

    Socket Socket::accept(sockaddr* addr, int* len)
    {
        Socket retval;
        retval.udtSocket = UDT::accept(udtSocket, addr, len);
        return retval;
    }

    int Socket::recvmsg(byte_t* buf, int len)
    {
        return UDT::recvmsg(udtSocket, (char*)buf, len);
    }
}