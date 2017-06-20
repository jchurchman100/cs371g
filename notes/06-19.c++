// -----------
// Mon, 19 Jun
// -----------

/*
iterator categories
iteration
function generics
function specializations
*/

template <typename T>
class list {
    public:
        using value_type = T;

        class iterator {
            ...};

        class const_iterator {
            ...};

        iterator begin () {
            return iterator(...);}

        const_iterator begin () const {
            return const_iterator(...);}

    ...};

int main () {
    list<int>           x = {...};
    list<int>::iterator p = x.begin();
    *p = 5;

    const list<int>           y = {...};
    list<int>::const_iterator q = y.begin();
    *q = 5;                                  // not ok

/*
members of vector, list, deque
need minimal requirements
copyable
assignable
default constructible

members of set, map (keys only)
also be comparable

members of unordered_set, unordered_map (keys only)
also be hashable
*/

// ---------
// Questions
// ---------

/*
What's a const method?
Non-const methods can be invoked on what kind of objects?
Const methods can be invoked on what kind of objects?
What happens when a class has overloaded a method only based on constness?
What kinds of methods come in pairs: const and non-const?
What are the requirements on elements of vector, list, and deque?
What are the requirements on elements of set and unordered_set?
What are the requirements on keys and values of map and unordered_map?
What can you not predict on unordered_set and unordered_map?
*/
