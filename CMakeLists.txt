cmake_minimum_required(VERSION 2.8)
project(oil_business)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTItHREADED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories("oil_business/header_files/")

set(SRC_DIR oil_business/source_files)

set(SRC_LIST ${SRC_DIR}/main.cpp ${SRC_DIR}/pipe.cpp ${SRC_DIR}/compressor_station.cpp ${SRC_DIR}/menu.cpp)

add_executable(${PROJECT_NAME}.exe ${SRC_LIST})
