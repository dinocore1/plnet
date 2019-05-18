#pragma once

#include "PLNet.h"

namespace plnet
{

/**
 * packet_type: 8uint
 * ttl: 8uint
 * dest_id: 
 * payload: var
 */
 
 #define PACKET_LEN 64

struct Packet {
    byte_t data[PACKET_LEN];
};

    
} // namespace plnet
