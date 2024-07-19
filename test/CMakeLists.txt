enable_testing()
find_package(GTest REQUIRED)
find_package(unordered_dense CONFIG REQUIRED)

file(GLOB TEST_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS *_tests.cpp)

include(GoogleTest)

foreach(TEST_FILE ${TEST_FILES})
  string(REGEX REPLACE "\.cpp" "" TEST ${TEST_FILE})
  add_executable(${TEST} ${TEST_FILE})
  target_link_libraries(${TEST} GTest::gtest_main GTest::gmock unordered_dense::unordered_dense)
  gtest_discover_tests(${TEST})
endforeach()
