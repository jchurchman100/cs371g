// -----------
// Wed, 14 Jun
// -----------

T*
    one T on the stack
    an array of Ts on the stack
    one T on the heap
    an array of Ts on the heap

int i = 2;
++*&i;

/*
clarity about values, addresses, references
in the context or arguments and returns
explore arrays
explore iteration
*/

// *, &
// type description, variable modifier

int* p; // type description
*p;     // variable modifier

int& r; // type description
&r      // variable modifier

int  a[] = {2, 3, 4};
int*  p = a;
int*& q = a; // not ok
++q;

int i = 2;
int j = i; // assignment? no; initialization

equal(a + 10, a + 15, b + 20);

void f (int v) {
    ...}

void g (int* p) {
    ++*p;}

void h (int& r) {
    ++r;}

int i = 2;
g(&i);
g(185); // not ok
g(0);   // ok, runtime error

h(i);
h(185); // not ok
h(0);   // not ok

const int i = 2;
int* p = &i; // not ok

int a[] = {2, 3, 4};
int b[] = {2, 3, 4};
double c[] = {2, 3, 5};
cout << equal(a, a + 3, b); // true;   T1 -> int*;    T2 -> double*
cout << equal(a, a + 3, c); // false

template <typename T1, typename T2>
bool equal (T1 a, T1 b, T2 c) {
    while (a != b) {
        if (*a != *c)
            return false;
        ++a;
        ++c;}
    return true;}

// for the code in the example slide

T1 -> list<int>::iterator
T2 -> vector<int>::iterator -> int*

// ---------
// Questions
// ---------

/*
In what two cases will pass by reference result in a compile time error instead of a logic error or a runtime error.
Under what circumstances is it still better to pass by address?
Under what circumstance does return by address result in a runtime error?
Under what circumstance does return by reference result in a runtime error?
For this call:
    equal(a + 10, a + 15, b + 20)
What's the smallest a can be? b can be?
*/
