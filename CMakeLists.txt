cmake_minimum_required(VERSION 3.14)
project(textanal)
# fake a block comment
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(textanal source/main.cpp source/filep.cpp source/filep.h source/computation.cpp source/computation.h source/statistics.cpp source/statistics.h source/algorithms.cpp source/algorithms.h)
