// --------------
// UnitTests3.c++
// --------------

// https://github.com/google/googletest
// https://github.com/google/googletest/blob/master/googletest/docs/Primer.md
// https://github.com/google/googletest/blob/master/googletest/docs/AdvancedGuide.md

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

#include "UnitTests3.h"

TEST(UnitTestsFixture, test_1) {
    ASSERT_EQ(1, cycle_length( 1));}

TEST(UnitTestsFixture, test_2) {
    ASSERT_EQ(6, cycle_length( 5));}

TEST(UnitTestsFixture, test_3) {
    ASSERT_EQ(7, cycle_length(10));}

/*
% locate libgtest.a
/lusr/lib/libgtest.a



% locate libgtest_main.a
/lusr/lib/libgtest_main.a



% locate libpthread.a
/usr/lib/x86_64-linux-gnu/libpthread.a



% g++ -pedantic -std=c++11 -Wall UnitTests3.c++ -o UnitTests3 -lgtest -lgtest_main -pthread



% UnitTests3
Running main() from gtest_main.cc
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from UnitTestsFixture
[ RUN      ] UnitTestsFixture.test_1
[       OK ] UnitTestsFixture.test_1 (0 ms)
[ RUN      ] UnitTestsFixture.test_2
[       OK ] UnitTestsFixture.test_2 (0 ms)
[ RUN      ] UnitTestsFixture.test_3
[       OK ] UnitTestsFixture.test_3 (0 ms)
[----------] 3 tests from UnitTestsFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 3 tests.
*/
