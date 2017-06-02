// -------------
// Coverage2.c++
// -------------

// http://gcc.gnu.org/onlinedocs/gcc/Gcov.html

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

#include "Coverage2.h"

TEST(CoverageFixture, test) {
    ASSERT_EQ(cycle_length(2), 2);}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++14 -Wall Coverage2.c++ -o Coverage2 -lgtest -lgtest_main -pthread



% Coverage2
Running main() from gtest_main.cc
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from CoverageFixture
[ RUN      ] CoverageFixture.test
[       OK ] CoverageFixture.test (0 ms)
[----------] 1 test from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.



% gcov -b Coverage2.c++ | grep -A 5 "File 'Coverage2.c++'"
File 'Coverage2.c++'
Lines executed:91.67% of 12
Branches executed:76.47% of 34
Taken at least once:41.18% of 34
Calls executed:55.88% of 34
Creating 'Coverage2.c++.gcov'
*/
