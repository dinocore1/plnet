
#include <gtest/gtest.h>

#include "Socket.h"

#include <arpa/inet.h>

using namespace plnet;

TEST(INetAddress, parse_string) {
    INetAddress socket("192.168.1.1", 4000);
    
    EXPECT_EQ(3232235777, ntohl(socket.ipv4addr));
    EXPECT_EQ(4000, socket.port);
}