add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(TEST_SOURCE_FILES chatTest.cpp userTest.cpp messageTest.cpp messageNotifierTest.cpp runAllTests.cpp chatTestFixture.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core)