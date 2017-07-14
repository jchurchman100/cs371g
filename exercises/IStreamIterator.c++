// -------------------
// IStreamIterator.c++
// -------------------

#include <algorithm> // copy,
#include <cassert>   // assert
#include <iostream>  // cout, endl, istream
#include <iterator>  // istream_iterator
#include <sstream>   // istringstream
#include <utility>   // !=
#include <vector>    // vector

#include "gtest/gtest.h"

#include "IStreamIterator.h"

using namespace std;

using std::rel_ops::operator!=;

using testing::Test;
using testing::Types;

int main () {
    using namespace std;
    cout << "IStreamIterator.c++." << endl;

    {
    const string        s = "2 3 4";
          istringstream in(s);
          vector<int>   x = {5, 6, 7, 8, 9};
    copy(my_istream_iterator<int>(in), my_istream_iterator<int>(), x.begin());
    assert(x == vector<int>({2, 3, 4, 8, 9}));
    }

    {
    const string        s = "2 3 4";
          istringstream in(s);
          vector<int>   x = {5, 6, 7, 8, 9};
    copy(istream_iterator<int>(in), istream_iterator<int>(), x.begin());
    assert(x == vector<int>({2, 3, 4, 8, 9}));
    }

    {
    istringstream in("2 3 4");
//  vector<int> x(my_istream_iterator<int>(in),   my_istream_iterator<int>());
    vector<int> x((my_istream_iterator<int>(in)), my_istream_iterator<int>());
    assert(x == vector<int>({2, 3, 4}));
    }

    {
    istringstream in("2 3 4");
//  vector<int> x(istream_iterator<int>(in),   istream_iterator<int>());
    vector<int> x((istream_iterator<int>(in)), istream_iterator<int>());
    assert(x == vector<int>({2, 3, 4}));
    }

    {
    istringstream in("2 3 4");
    my_istream_iterator<int> b(in);
    my_istream_iterator<int> e;
    vector<int> x(b, e);
    assert(x == vector<int>({2, 3, 4}));
    }

    {
    istringstream in("2 3 4");
    istream_iterator<int> b(in);
    istream_iterator<int> e;
    vector<int> x(b, e);
    assert(x == vector<int>({2, 3, 4}));
    }

    cout << "Done." << endl;
    return 0;}
