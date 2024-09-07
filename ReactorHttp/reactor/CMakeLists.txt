cmake_minimum_required(VERSION 3.10)
project(Reactor)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
# add_library(REACTOR STATIC ${SRC})
add_library(REACTOR SHARED ${SRC})