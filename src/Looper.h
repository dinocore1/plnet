#pragma once

namespace plnet
{
    struct Message {
        int what;
        int arg1;
        int arg2;
        void* data;
    };
    
} // namespace plnet
