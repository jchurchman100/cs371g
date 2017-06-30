// -----------------
// PriorityQueue.c++
// -----------------

// http://en.cppreference.com/w/cpp/container/priority_queue

#include <cassert>    // assert
#include <deque>      // deque
#include <functional> // less
#include <queue>      // priority_queue
#include <vector>     // vector

#include "gtest/gtest.h"

#include "PriorityQueue.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct PriorityQueue_Fixture : Test {
    using priority_queue_type = T;};

using
    priority_queue_types =
    Types<
              priority_queue<int>,
              priority_queue<int, deque<int>, less<int>>,
           my_priority_queue<int>,
           my_priority_queue<int, deque<int>, less<int>>>;

TYPED_TEST_CASE(PriorityQueue_Fixture, priority_queue_types);

TYPED_TEST(PriorityQueue_Fixture, test_1) {
    using priority_queue_type = typename TestFixture::priority_queue_type;

    priority_queue_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(), 0);

    x.push(2);
    x.push(3);
    x.push(4);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(3, x.size());
    ASSERT_EQ(4, x.top());

    x.pop();
    ASSERT_EQ(2, x.size());
    ASSERT_EQ(3, x.top());

//  x.top() = 4; // error: cannot assign to return value because function 'top' returns a const value
    }

TYPED_TEST(PriorityQueue_Fixture, test_2) {
    using priority_queue_type = typename TestFixture::priority_queue_type;

    priority_queue_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    priority_queue_type y = x;

    y.pop();
    ASSERT_EQ(3, x.size());
    ASSERT_EQ(4, x.top());
    ASSERT_EQ(2, y.size());
    ASSERT_EQ(3, y.top());}

TYPED_TEST(PriorityQueue_Fixture, test_3) {
    using priority_queue_type = typename TestFixture::priority_queue_type;

    priority_queue_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    priority_queue_type y;
    y.push(5);
    y.push(6);

    y = x;

    y.pop();
    ASSERT_EQ(3, x.size());
    ASSERT_EQ(4, x.top());
    ASSERT_EQ(2, y.size());
    ASSERT_EQ(3, y.top());}
