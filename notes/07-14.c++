// -----------
// Fri, 14 Jul
// -----------

A x(v);
A x = v;

A y(v, w);
A y = (v, w); // not ok
A y = {v, w};

/*
iterator adapters
*/

vector<int> x{2, 3, 4};
vector<int> y[3];
copy(begin(x), end(x), begin(y));

vector<int> x{2, 3, 4};
vector<int> y;
copy(begin(x), end(x), begin(y)); // not ok

template <typename C>
class back_insert_iterator {
    private:
        C& _c;
    public:
        back_insert_iterator (C& c) :
            _c (c)
            {}

        back_insert_iterator& operator * () {
            return *this;}

        back_insert_iterator& operator ++ () {
            return *this;}

        back_insert_iterator& operator = (C::const_reference v) {
            _c.push_back(v);
            return *this;}};

template <typename C>
back_insert_iterator<C> back_inserter (C& c) {
    return back_insert_iterator<C>(c);}

vector<int> x{2, 3, 4};
vector<int> y;
copy(begin(x), end(x), back_insert_iterator<vector<int>>(c));

vector<int> x{2, 3, 4};
vector<int> y;
copy(begin(x), end(x), back_inserter(y));

void f (pair<int, int> p) {
    ...}

int main () {
    pair<int, int> q(2, 3);
    f(q);

    f(pair<int, int>(2, 3));

    f(2, 3);   // not ok
    f({2, 3}); // not ok

    f(make_pair(2, 3));

    cout << max<double>(2.3, 3);
    cout << max(2.3, 3.4);

    vector<int> x(10, 2);
    vector<int> x(10);

/*
function template can deduce their template arguments from their function arguments.
class template will NOT deduce their template arguments from their function arguments.
*/

// ---------
// Questions
// ---------

/*
What are the requirements of keys in set?
What are the requirements of keys in map?
What are the requirements of values in map?
What will set and map not allow you to modify in place? Why not?
What does map's subscript operator do when searching for a non-existent key?
What is make_pair?
What is back_insert_iterator?
What is the trick to avoid default constructing an element in back_insert_iterator?
What is back_inserter?
*/
