cmake_minimum_required(VERSION 3.20.1 FATAL_ERROR)
project(mtest VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra") 
set(CMAKE_CXX_EXTENSIONS OFF) 

set(ENV{PKG_CONFIG_PATH} "/usr/lib/pkgconfig/")
find_package(PkgConfig REQUIRED)
# find_package(glog 0.7.0 REQUIRED)

INCLUDE_DIRECTORIES("/usr/include")
LINK_DIRECTORIES("/usr/lib")
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/head)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCES) 

add_executable(mtest ${SOURCES})
target_link_libraries(mtest)