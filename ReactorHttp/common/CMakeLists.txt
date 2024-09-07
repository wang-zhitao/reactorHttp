cmake_minimum_required(VERSION 3.10)
project(Common)


file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
# add_library(COMMON STATIC ${SRC})
add_library(COMMON SHARED ${SRC})
target_link_libraries(COMMON REACTOR)