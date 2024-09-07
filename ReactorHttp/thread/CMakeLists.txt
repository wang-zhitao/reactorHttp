cmake_minimum_required(VERSION 3.10)
project(Thread)


file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
# add_library(THREAD STATIC ${SRC})
add_library(THREAD SHARED ${SRC})
target_link_libraries(THREAD pthread)