if(EXISTS "D:/Workspace/C++/textanal/cmake-build-debug/cmake-build-debug/googletest/hello_test[1]_tests.cmake")
  include("D:/Workspace/C++/textanal/cmake-build-debug/cmake-build-debug/googletest/hello_test[1]_tests.cmake")
else()
  add_test(hello_test_NOT_BUILT hello_test_NOT_BUILT)
endif()