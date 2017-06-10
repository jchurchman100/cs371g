// ----------
// Fri, 9 Jun
// ----------

/*
testing
    assertions
        not for unit tests, Google Test instead
        not for user errors, exceptions instead
*/

int f (...) {
    ...
    if (...) {
        throws Child(...); // throw always copies what it throws
    ...}

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
    catch (Parent& e) { // always catch by reference
        ...}
//    catch (Child e) { // define the chile catcher first
//        ...}
    ...}

...
...g(...)...
...

/*
Doesn't have that!
C++ string has an == operator that takes a C++ string on the left and a C string on the right.
*/

void f (string s) {
    ...}

void g () {
    string t("abc");
    f(t);     // ok
    f("abc"); // ok

/*
lots of implicit type conversions:
Java
    double to int, not ok
    int to double, ok

C++
    both are ok
    C string to C++ string, ok
*/

const char* a
char* const a

int my_strcmp (const char* a, const char* b) {
    while ((*a != 0) && (*a == *b)) {
        ++a;
        ++b;}
    return *a - *b;}

// ---------
// Questions
// ---------

/*
What is the catch clause?
What is rethrowing?
Should you catch by value, by address, or by reference? Why?
What's an implicit type conversion?
What is shared_ptr? Unique_ptr?
What is union?
What is enum?
*/
