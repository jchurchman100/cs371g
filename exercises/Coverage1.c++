// -------------
// Coverage1.c++
// -------------

// http://gcc.gnu.org/onlinedocs/gcc/Gcov.html

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

#include "Coverage1.h"

TEST(CoverageFixture, test) {
    ASSERT_EQ(cycle_length(1), 1);}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++14 -Wall Coverage1.c++ -o Coverage1 -lgtest -lgtest_main -pthread



% Coverage1
Running main() from gtest_main.cc
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from CoverageFixture
[ RUN      ] CoverageFixture.test
[       OK ] CoverageFixture.test (0 ms)
[----------] 1 test from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (1 ms total)
[  PASSED  ] 1 test.



% gcov -b Coverage1.c++ | grep -A 5 "File 'Coverage1.c++'"
File 'Coverage1.c++'
Lines executed:100.00% of 2
Branches executed:69.23% of 26
Taken at least once:34.62% of 26
Calls executed:59.38% of 32
Creating 'Coverage1.c++.gcov'
*/
