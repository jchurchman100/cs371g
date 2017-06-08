// -------------
// Coverage1.c++
// -------------

// http://gcc.gnu.org/onlinedocs/gcc/Gcov.html

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

#include "Coverage1.h"

TEST(CoverageFixture, test) {
    ASSERT_EQ(1, cycle_length(1));}

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



% gcov -b Coverage1.c++ | grep -A 5 "File './Coverage1.h'"
File './Coverage1.h'
Lines executed:55.56% of 9
Branches executed:75.00% of 8
Taken at least once:37.50% of 8
No calls
./Coverage1.h:creating 'Coverage1.h.gcov'
*/
