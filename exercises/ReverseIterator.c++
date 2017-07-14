// -------------------
// ReverseIterator.c++
// -------------------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // reverse_iterator
#include <string>    // string

#include "gtest/gtest.h"

#include "ReverseIterator.h"

using namespace std;

using testing::Test;
using testing::Types;

int main () {
    using namespace std;
    cout << "ReverseIterator.c++" << endl;

    {
    const string s = "Cba";
          string t = "xxxbA";
    my_reverse_iterator<string::const_iterator> b(s.end());
    my_reverse_iterator<string::const_iterator> e(s.begin());
    copy(b, e, t.begin());
    assert(t == "abCbA");
    }

    {
    const string s = "Cba";
          string t = "xxxbA";
    reverse_iterator<string::const_iterator> b(s.end());
    reverse_iterator<string::const_iterator> e(s.begin());
    copy(b, e, t.begin());
    assert(t == "abCbA");
    }

    cout << "Done." << endl;
    return 0;}
