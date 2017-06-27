// --------------------------------
// projects/integer/TestInteger.c++
// Copyright (C) 2017
// Glenn P. Downing
// --------------------------------

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Integer.h"

using namespace std;

// ----
// read
// ----

TEST(IntegerFixture, test) {
    Integer<int> x = 0;
    ASSERT_EQ(&x, &x);}
