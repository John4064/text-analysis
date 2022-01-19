cmake_minimum_required(VERSION 3.14)
project(textanal)
# fake a block comment
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/2d07f12b607c528b21795ab672cff3afaf64f7a1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        hello_test
        hello_test.cc
)
target_link_libraries(
        hello_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)




#add_executable(textanal source/main.cpp source/filep.cpp source/filep.h source/computation.cpp source/computation.h)
