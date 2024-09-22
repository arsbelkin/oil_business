cmake_minimum_required(VERSION 2.8)
project(oil_business.exe)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTItHREADED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SRC_DIR oil_business)

set(SRC_LIST ${SRC_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})
