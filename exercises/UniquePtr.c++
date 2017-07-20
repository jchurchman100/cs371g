// -------------
// UniquePtr.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/unique_ptr

#include <memory>     // default_delete, unique_ptr
#include <functional> // function
#include <utility>    // move

#include "gtest/gtest.h"

#include "UniquePtr.h"

using namespace std;
using namespace testing;

struct A {
    static int c;

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

template <typename T>
struct UniquePtrFixture : Test {
    using unique_ptr_type = T;};

template <typename T>
struct UniquePtrFixture2 : Test {
    using unique_ptr_type2 = T;};

using
    unique_ptr_types =
    Types<
           unique_ptr<A>,
        my_unique_ptr<A>>;

using
    unique_ptr_types2 =
    Types<
           unique_ptr<A, std::function<void (A*)>>,
        my_unique_ptr<A, std::function<void (A*)>>>;

TYPED_TEST_CASE(UniquePtrFixture,  unique_ptr_types);
TYPED_TEST_CASE(UniquePtrFixture2, unique_ptr_types2);

TYPED_TEST(UniquePtrFixture, test_1) {
    using unique_ptr_type = typename TestFixture::unique_ptr_type;
    ASSERT_EQ(0, A::c);
    {
//  unique_ptr_type x = new A; // error: no viable conversion from 'A *' to 'unique_ptr_type'
    unique_ptr_type x(new A);
    ASSERT_EQ(1, A::c);
    }
    ASSERT_EQ(0, A::c);}

TYPED_TEST(UniquePtrFixture, test_2) {
    using unique_ptr_type = typename TestFixture::unique_ptr_type;
    ASSERT_EQ(0, A::c);
    {
    unique_ptr_type x(new A);
    ASSERT_EQ(1, A::c);
//  unique_ptr_type y = x;       // error: call to implicitly-deleted copy constructor of 'unique_ptr_type'
//  unique_ptr_type y(x);        // error: call to implicitly-deleted copy constructor of 'unique_ptr_type'
    unique_ptr_type y = move(x);
    ASSERT_EQ(1,       A::c);
    ASSERT_EQ(nullptr, x.get());
    }
    ASSERT_EQ(0, A::c);}

TYPED_TEST(UniquePtrFixture, test_3) {
    using unique_ptr_type = typename TestFixture::unique_ptr_type;
    ASSERT_EQ(0, A::c);
    {
    unique_ptr_type x(new A, default_delete<A>());
    unique_ptr_type y(new A, default_delete<A>());
    ASSERT_EQ(2, A::c);
//  x = y;                       // error: object of type 'std::__1::unique_ptr<A, std::__1::default_delete<A> >' cannot be assigned because its copy assignment operator is implicitly deleted
    x = move(y);
    ASSERT_EQ(1,       A::c);
    ASSERT_EQ(nullptr, y.get());
    }
    ASSERT_EQ(0, A::c);}

TYPED_TEST(UniquePtrFixture2, test_4) {
    using unique_ptr_type = typename TestFixture::unique_ptr_type2;
    ASSERT_EQ(0, A::c);
    {
    unique_ptr_type x(new A, [] (A* p) -> void {delete p;});
    unique_ptr_type y(new A, [] (A* p) -> void {delete p;});
    ASSERT_EQ(2, A::c);
//  x = y;                       // error: object of type 'std::__1::unique_ptr<A, std::__1::default_delete<A> >' cannot be assigned because its copy assignment operator is implicitly deleted
    x = move(y);
    ASSERT_EQ(1,       A::c);
    ASSERT_EQ(nullptr, y.get());
    }
    ASSERT_EQ(0, A::c);}
