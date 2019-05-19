
#include <arpa/inet.h>
#include "Socket.h"

namespace plnet
{
    INetAddress::INetAddress(const string& addrStr, uint16_t port)
    {
        inet_pton(AF_INET, addrStr.c_str(), &ipv4addr);
        this->port = port;
    }
}