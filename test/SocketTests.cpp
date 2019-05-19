
#include <gtest/gtest.h>

#include "Socket.h"

using namespace plnet;

TEST(INetAddress, parse_string) {
    INetAddress socket("127.0.0.1", 4000);
    
}