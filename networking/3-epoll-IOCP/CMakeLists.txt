cmake_minimum_required(VERSION 3.16)

project(3-epoll-IOCP)
set(CMAKE_CXX_STANDARD 14)

add_definitions(-DASIO_STANDALONE -D_WIN32_WINNT=0x0501)
include_directories(D:/Programmering/C++/repos/asio-1.16.1/include)

add_executable(3-epoll-IOCP ${PROJECT_SOURCE_DIR}/main.cpp)