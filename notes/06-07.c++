// ----------
// Wed, 7 Jun
// ----------

/*
(3n + 1) / 2
3n/2 + 1/2
3n/2 + 1
n + n/2 + 1
n + (n >> 1) + 1

b = 10
e = 100
m = 51
mcl(10, 100) = mcl(51, 100)

b = 200
e = 300
m = 151

nature of testing

assertions
    good for preconditions, postconditions, loop invariants
    good for programmer error

    not good for unit testing, a good solution is unit testing framework like Google Test
    not good for user error, a good solution are exceptions

5 16 8 4 2 1
cycle length of 5 is 6

how good are my tests?
run a coverage tool
gcov

exercise to show that bad tests can hide bad code

1. identify the bad tests
2. fix the tests
3. identify the bad code
4. fix the code
*/

for (I i = 0; i < s; i++) {
    ...}

{
int i = 0;
while (i < s) {
    ...
    i++;}
}

(i += j)++;  // not in C, Java, Python, ok in C++

int i = 2;
int j = ++i; // pre-increment, cheap
cout << i;   // 3
cout << j;   // 3
++++i;       // ok

++i;

int i = 2;
int j = i++; // post-increment, expensive
cout << i;   // 3
cout << j;   // 2
i++++;       // not ok

i++; -> ++i; // for built-in types, but NOT for user-defined types

// int h = 0;

int f (..., int& e2) {
    ...
    if (/* something wrong */) {
//        ::h = -1;
        e2 = -1;
        throw ???;
        return ...;}
    ...

int g (...) {
    ...
//    h = 0;
//    int e = 0;
    Integer e = new Integer(0);
    int i = f(..., e);
    try {
        int i = f(...);}
    if (e == -1)
    catch (???)
        /* something wrong */
    ...

...
...g(...)...
...

// ---------
// Questions
// ---------

/*
What are assertions good for? Not good for?
Other than exceptions, what are the three avenues of communication?
What's a good solution for unit testing?
What libraries does Google Test need?
Will an internal assertion failure stop Google Test?
What is gcov?
*/
