// ----------------
// BackInserter.c++
// ----------------

// http://en.cppreference.com/w/cpp/iterator/back_inserter

#include <algorithm>        // equal
#include <initializer_list> // initializer_list
#include <iterator>         // back_insert_iterator
#include <vector>           // vector

#include "gtest/gtest.h"

#include "BackInserter.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct Back_Insert_Iterator_Fixture : Test {
    typedef T back_insert_iterator_type;};

using
    back_insert_iterator_types =
    Types<
           back_insert_iterator<vector<int>>,
        my_back_insert_iterator<vector<int>>>;

TYPED_TEST_CASE(Back_Insert_Iterator_Fixture, back_insert_iterator_types);

TYPED_TEST(Back_Insert_Iterator_Fixture, test) {
    typedef typename TestFixture::back_insert_iterator_type back_insert_iterator_type;

    const initializer_list<int>     x = {5, 6};
          vector<int>               y = {2, 3, 4};
          back_insert_iterator_type z(y);
    copy(begin(x), end(x), z);
    ASSERT_TRUE(equal(begin(y), end(y), begin({2, 3, 4, 5, 6})));}
