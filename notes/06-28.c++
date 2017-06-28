// -----------
// Wed, 28 Jun
// -----------

/*
finish iterators and algorithms
start container and container adapters
*/

template <typename II, typename OI, typename UF>
OI transform (II b, II e, OI x, UF f) {
    while (b != e) {
        *x = f(*b);
        ++b;
        ++x;}
    return x;}

/*
S <b> a[0] <b> a[1] <b> ...

S   = 0
<b> = +
sum

S   = 1
<b> = *
product
*/

template <typename II, typename T, typename BF>
T accumulate (II b, II e, T seed, BF f) {
    while (b != e) {
        seed = f(seed, *b)
        ++b;}
    return seed;}

square2<int> x;
cout << x(3);            // 9
cout << x.operator()(3); // 9
cout << square2<int>()(3);    // 9

cout << square2<int>(3);      // not ok

square3<int> y;             // not ok
square3<int> y(2);
cout << y(3);               // 9
cout << y.operator()(3);    // 9
cout << square3<int>(2)(3); // 9

cout << square3<int>(2); // not ok

cout << square3<int>(2).operator()(3); // 9

/*
vector
list
deque

cost of
adding to the beginning, the middle, the end
remove from the beginning, the middle, the end
indexing
/*

/*
vector
push_back (amortized O(1))
push_front: not there
insert: O(n)

pop_back: O(1)
pop_front: not there
remove: O(n)

index: O(1)
*/

vector<int> x(10, 2);
vector<int>::iterator p = begin(x);
cout << *p;     // 2
x.push_back(3);
cout << *p;     // not ok

/*
list
push_back: O(1)
push_front: O(1)
insert: O(1)

pop_back: O(1)
pop_front: O(1)
remove: O(1)

index: not there
*/

/*
deque
array of arrays
*/

deque<int> x(10, 2); // 1 outer array, size 1; 1 inner array, size 10
deque<int>::iterator p = begin(x);
cout << *p;     // 2
x.push_back(3);      // 1 outer array, size 2: 2 inner arrays, size 10
cout << *p;     // ok

// ---------
// Questions
// ---------

/*
What's a lambda?
What's a mutable lambda?
What's a closure?
How is vector implemented? List? Deque?
What are the complexities of adding, removing, and indexing elements for vector, list, and deque?
Under what circumstances are iterators, pointers, and references invalidated on vectors?
*/
