// -----------
// Mon,  3 Jul
// -----------

template <typename T>
struct less {
    bool operator () (const T& lhs, const T& rhs) const {
        return lhs < rhs;}};

struct A {
    int i;
    double x;};

int main () {
    less<int> x;
    cout << x(2, 3);           // true
    cout << less<int>()(2, 3); // true

    int* p = new int[3];       // three ints
    fill(p, p + 3, 2);
    delete [] p;               // [] very important

    int* q = new int(2);       // single int
    ...
    delete q;

    T* const p = new T[s];     // T(),  s times
    fill(p, p + s, 2);         // =(T), s times
    ++p;                       // not ok
    ++*p;
    delete [] p;               // ~T(), s times

    int i = 2;
    i = 3;
    delete &i;

    int a[] = {2, 3, 4};

    A x = {2, 3,5};

    intializer_list<int> y = {2, 3, 4};

    vector<int> v1(10, 2);    // size 10, value 2
    vector<int> v2{10, 2};    // size 2,  values 10 and 2
    vector<int> v3 = (10, 2); // not ok
    vector<int> v4 = {10, 2};

/*
mistakes can I make with new and delete:

1. deleting an already deleted object
2. losing track of what new gave you earlier
3. incorrect use of the brackets
4. deleting wrong the address
*/

/*
vector:
    constructor:
        default
        size
        size and value
        initializer_list

    index, two of them

    begin, two of them
    end,   two of them

    size
*/

/*
kinds of casts:
    const_cast
    static_cast
    reinterpret_cast
    dynamic_cast
*/

// ---------
// Questions
// ---------

/*
What is the default comparator for priority_queue?
Why does priority_queue have top() instead of back() and front()?
Why does priority_queue only have one top()?
What is less<T>?
What does new T[s] invoke and how many times?
What does fill(a, a + s, v) invoke and how many times?
When is it important to use [] in new and delete?
What is initializer_list<T>?
Should the const method call the non-const method for reuse or the other way around? Why?
*/
