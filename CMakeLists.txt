cmake_minimum_required(VERSION 3.20)
project(textanal)
# fake a block comment
set(CMAKE_CXX_STANDARD 11)

add_executable(textanal source/main.cpp source/filep.cpp source/filep.h source/computation.cpp source/computation.h)
