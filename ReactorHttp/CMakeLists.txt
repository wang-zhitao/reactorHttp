cmake_minimum_required(VERSION 3.12)
project(ReactorHttp)
# 开启优化选项
set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_STANDARD 11)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_CURRENT_SOURCE_DIR}/http
    ${CMAKE_CURRENT_SOURCE_DIR}/reactor
    ${CMAKE_CURRENT_SOURCE_DIR}/tcp
    ${CMAKE_CURRENT_SOURCE_DIR}/thread
    )

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_compile_definitions(
                        # DEBUG
                        # MSG_SEND_AUTO
                        # EPOLLET_ENABLE (存在BUG)
                        EPOLLLT_ENABLE
                        # SELECT_ENABLE
                        # POLL_ENABLE
                        )

add_subdirectory(common)
add_subdirectory(http)
add_subdirectory(reactor)
add_subdirectory(tcp)
add_subdirectory(thread)

 set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(ReactorHttp  main.cpp)
target_link_libraries(ReactorHttp TCP THREAD)

