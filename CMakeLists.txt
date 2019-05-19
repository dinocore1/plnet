cmake_minimum_required (VERSION 3.10)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(DownloadProject)

project(PLNet)
set(CMAKE_CXX_STANDARD 14)
set (PLNET_VERSION_MAJOR 1)
set (PLNET_VERSION_MINOR 0)
option(BUILD_TESTS "Build unit tests" ON)

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
target_compile_definitions(udt PRIVATE UDT_EXPORTS OSX)

include_directories(src)
add_library(plnet 
    "src/Id.cpp"
    "src/Socket.cpp"
    )
target_link_libraries(plnet udt)

add_executable(plnet_client
    "src/main.cpp"
    )
target_link_libraries(plnet_client plnet)

if(BUILD_TESTS)
    download_project(PROJ               googletest
                    GIT_REPOSITORY      https://github.com/google/googletest.git
                    GIT_TAG             master
    )
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

    add_executable(tests 
        "test/SocketTests.cpp"
        )
    target_link_libraries(tests plnet gtest gmock_main)
    add_test(NAME tests COMMAND tests)

endif()
