cmake_minimum_required(VERSION 3.20)
project(textanal)
# fake a block comment
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        hello_test
        source/hello_test.cc)
target_link_libraries(
        hello_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)




add_executable(textanal source/main.cpp source/filep.cpp source/filep.h source/computation.cpp source/computation.h source/hello_test.cc source/hello_test.cpp)
