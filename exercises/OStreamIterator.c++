// -------------------
// OStreamIterator.c++
// -------------------

#include <algorithm>        // copy
#include <initializer_list> // initializer_list
#include <iterator>         // ostream_iterator
#include <sstream>          // ostringstream

#include "gtest/gtest.h"

#include "OStreamIterator.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct OStream_Iterator_Iterator_Fixture : Test {
    typedef T ostream_iterator_type;};

using
    ostream_iterator_types =
    Types<
           ostream_iterator<int>,
        my_ostream_iterator<int>>;

TYPED_TEST_CASE(OStream_Iterator_Iterator_Fixture, ostream_iterator_types);

TYPED_TEST(OStream_Iterator_Iterator_Fixture, test) {
    typedef typename TestFixture::ostream_iterator_type ostream_iterator_type;

    initializer_list<int> x = {2, 3, 4};
    ostringstream out;
    copy(begin(x), end(x), ostream_iterator_type(out, " "));
    ASSERT_EQ("2 3 4 ", out.str());}
