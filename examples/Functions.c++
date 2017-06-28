// -------------
// Functions.c++
// -------------

#include <algorithm>  // transform
#include <cassert>    // assert
#include <cmath>      // pow
#include <functional> // function, plus
#include <iostream>   // cout, endl
#include <list>       // list

using namespace std;

template <typename T>
T square1 (const T& v) {
    return pow(v, 2);}

template <typename T>
struct square2 {
    T operator () (const T& v) const {
        return pow(v, 2);}};

template <typename T>
struct square3 {
    T _w;

    square3 (const T& w) :
        _w (w)
        {}

    T operator () (const T& v) const {
        return pow(v, _w);}};

int main () {
    cout << "Funcitons.c++" << endl;

    list<int> x = {2, 3, 4};

    {
    list<int> y(3);
    transform(begin(x), end(x), begin(y), &square1<int>);
    assert(equal(begin(y), end(y), begin({4, 9, 16})));
    }

    {
    list<int> y(3);
    transform(begin(x), end(x), begin(y), square1<int>);
    assert(equal(begin(y), end(y), begin({4, 9, 16})));
    }

    {
    list<int> y(3);
    transform(begin(x), end(x), begin(y), [] (int v) -> int {return pow(v, 2);});
    assert(equal(begin(y), end(y), begin({4, 9, 16})));
    }

    {
    list<int> y(3);
    int w = 2;
    transform(begin(x), end(x), begin(y), [w] (int v) -> int {return pow(v, w);});
    assert(equal(begin(y), end(y), begin({4, 9, 16})));
    }
/*
    {
    list<int> y(3);
    int w = 2;
    transform(begin(x), end(x), begin(y), [w] (int v) -> int {++w; return pow(v, w);}); // error: cannot assign to a variable captured by copy in a non-mutable lambda
    }
*/
    {
    list<int> y(3);
    int w = 2;
    transform(begin(x), end(x), begin(y), [&w] (int v) -> int {++w; return pow(v, w);});
    assert(equal(begin(y), end(y), begin({8, 81, 1024})));
    assert(w == 5);
    }

    {
    list<int> y(3);
    transform(begin(x), end(x), begin(y), square2<int>());
    assert(equal(begin(y), end(y), begin({4, 9, 16})));
    }

    {
    list<int> y(3);
    transform(begin(x), end(x), begin(y), square3<int>(2));
    assert(equal(begin(y), end(y), begin({4, 9, 16})));
    }

    cout << "Done." << endl;
    return 0;}
