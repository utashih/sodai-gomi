cmake_minimum_required (VERSION 3.10)
project(hashtag)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
elseif (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native")
endif()

add_library(treap treap.cpp) 

add_executable(treap_test treap_test.cpp)
target_link_libraries(treap_test treap gtest glog gflags)
add_test(NAME treap_test COMMAND treap_test)
