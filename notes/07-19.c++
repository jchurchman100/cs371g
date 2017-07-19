// -----------
// Wed, 19 Jul
// -----------

vector<int> x = {2, 3, 4};
vector<int>::iterator b = begin(x);
vector<int>::iterator e = end(x);
cout << *b;
cout << *e; // not ok

// smart pointers

int* p = new int;
delete p;

int* a = new int[s];
delete [] a;

template <typename T, typename D = default_delete<T>>
class unique_ptr {
    private:
        T* _p = nullptr;
        D  _d;

    public:
        unique_ptr (T* p, const D& d = D()) :
            _p (p),
            _d (d)
            {}

        unique_ptr (const unique_ptr&) = delete;
        unique_ptr& operator = (const unique_ptr&) = delete;

        ~unique_ptr () {
            _d(_p);}

        unique_ptr (unique_ptr&& rhs) :
            _d (move(rhs._d)) {
            swap(_p, rhs._p);}

        unique_ptr& operator = (unique_ptr&& rhs) {
            if (_p == rhs._p)
                return *this;
            _d(_p);
            _d = move(rhs._d);
            _p(rhs._p);
            rhs._p = nullptr;}

// ---------
// Questions
// ---------

/*
What is unique_ptr?
What operations are turned off? How are they turned off?
*/
