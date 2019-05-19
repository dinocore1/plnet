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

        void bind(const INetAddress&);

        UDTSOCKET udtSocket;
    };
    
} // namespace plnet
