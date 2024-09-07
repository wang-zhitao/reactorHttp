cmake_minimum_required(VERSION 3.10)
project(Tcp)


file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
# add_library(TCP STATIC ${SRC})
add_library(TCP SHARED ${SRC})
target_link_libraries(TCP COMMON HTTP)