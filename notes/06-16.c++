// -----------
// Fri, 16 Jun
// -----------

/*
finish conversation about values, address, and references

explore the notion of iterator categories and what algorithms need

iterator concepts

input iterator (II) responds to
    ==, !=
    * (read only)
    ++

output iterator (OI) responds to
    * (write only)
    ++

forward iterator (FI) responds to (extends input iterator)
    ==, !=
    * (read / write)
    ++

bidirectional iterator (BI) responds to (extends forward iterator)
    ==, !=
    * (read / write)
    ++
    --

random access iterator (RI) responds to (extends bidirectional iterator)
    ==, !=
    * (read / write)
    ++
    --
    []
    +
    -
    <, >, <=, >=
*/

int& pre_incr (int& r) {
    r = r + 1;     r += 1;        ++r;
    return r;

int post_incr (int& r) {
    int v = r;
    r += 1;              ++r;           r = r + 1;
    return v;

equal(a + 10, a + 15, b + 20);

template <typename II, typename OI>
OI copy (II b, II e, OI c) {
    while (b != e) {
        *c = *b;
        ++b;
        ++c;}
    return c;}

template <typename FI, typename T>
void fill (FI b, FI e, T v) {
    while (b != e) {
        *b = v;
        ++b;}}

/*
from the algorithm side

equal
    input iterators

copy
    input / output

fill
    forward

reverse
    bidirectional

sort
    random access

from the containter side

input stream
    input

output stream
    output

forward_list
    forward

list
    bidirectional

vector
    random access

In Java

List interface
    get(index)

define sort (List)

what implements List
    ArrayList
    LinkedList
    DequeList

In C++ calling sort on list, fails to compile.
In Java calling sort on LinkedList, runs, and runs very slowly!!!
*/

// ---------
// Questions
// ---------

/*
In C++ what is the return type of pre-increment? In C? In Java?
What are the five categories of iterators and what operations do they support?
What category iterator does equal() need? copy()? fill()? reverse()? sort()?
What category of iterator does istream_iterator provide? ostream_iterator? forward_list? list? vector?
*/
