// -----------
// Wed, 12 Jul
// -----------

vector<int> x(10, 2); // 10 ints of value 2
vector<int> y{10, 2}; //  2 ints of values 10 and 2

struct A {
    int    i;
    double d;};

int main () {
    A x = {2, 3.4};

    pair<int, int> p(2, 3);
    pair<int, int> q{2, 3};
    pair<int, int> r = {2, 3};

template <typename T1, typename T2>
struct pair {
    T1 first;
    T2 second;

    pair (const T1& f = T1(), const T2 s = T2()) :
        first  (f)
        second (s)
        {}

    pair (const pair& rhs) :
        first  (rhs.first),
        second (rhs.second)
        {}

    template <typename U1, typename U2>
    pair (const pair<U1, U2>& rhs) :
        first  (rhs.first),
        second (rhs.second)
        {}

int main () {
    pair<double, double> p(2.34, 5.67);
    pair<int,    int>    q(8, 9);
    p = q;

struct A {
    ...};

int main () {
    A x(2, 3);
    A y(4);
    A z();     // odd meaning: a function, named z, that takes no args and returns an A
    A t;

    A* p = new A(2, 3);
    A* q = new A(4);
    A* r = new A();
    A* s = new A;

    A z = A();

    int i = int();

// ---------
// Questions
// ---------

/*
What is the behavior of the Boost graph functions in TestGraph.c++?
What is pair<T1, T2>?
Why did we define a templated copy constructor for pair<T1, T2>?
Why did we NOT define a templated copy assignment for pair<T1, T2>?
When do {} act as a non-initializer-list constructor?
*/
