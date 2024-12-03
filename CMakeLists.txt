cmake_minimum_required(VERSION 3.30)
project(oil_business)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTItHREADED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")

include_directories("oil_business/header_files/")

set(SRC_DIR oil_business/source_files)

set(SRC_LIST
    ${SRC_DIR}/main.cpp 
    ${SRC_DIR}/pipe.cpp 
    ${SRC_DIR}/compressor_station.cpp 
    ${SRC_DIR}/menu.cpp 
    #${SRC_DIR}/utils.cpp
    #${SRC_DIR}/pipes_func.cpp
    ${SRC_DIR}/filter.cpp
    #${SRC_DIR}/CS_func.cpp
    ${SRC_DIR}/logger.cpp
    ${SRC_DIR}/GTN.cpp
    )

add_executable(${PROJECT_NAME}.exe ${SRC_LIST})
