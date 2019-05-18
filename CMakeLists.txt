cmake_minimum_required (VERSION 3.10)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

project(PLNet)
set(CMAKE_CXX_STANDARD 14)

list(APPEND UDT_SRCS
    "udt/api.cpp"
    "udt/buffer.cpp"
    "udt/cache.cpp"
    "udt/ccc.cpp"
    "udt/channel.cpp"
    "udt/common.cpp"
    "udt/core.cpp"
    "udt/epoll.cpp"
    "udt/list.cpp"
    "udt/md5.cpp"
    "udt/packet.cpp"
    "udt/queue.cpp"
    "udt/window.cpp"
    )

include_directories(udt)
add_library (udt ${UDT_SRCS})