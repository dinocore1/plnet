#pragma once

#include <udt.h>

#include "PLNet.h"

namespace plnet
{
    class INetAddress {
        public:
        INetAddress(const string&, uint16_t port);

        uint32_t ipv4addr;
        uint16_t port;
    };

    class Socket {
        public:

        static int create(int af, int type, Socket*);
        int bind(const INetAddress&);
        int listen(int backlog);
        Socket accept(sockaddr*, int* len);

        int recvmsg(byte_t* buf, int len);

        UDTSOCKET udtSocket;
    };
    
} // namespace plnet
