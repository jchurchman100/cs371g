// -----------
// Wed,  5 Jul
// -----------

/*
elaborate the implementation of vector
*/

T i = 2; // initialization, for non-explicit one-arg constructors
i = 2;   // assignment

void f (vector<int> v) {
    v[i] = 5;}

int main () {
    vector<int> x(10, 2);
    f(x);

template <typename T>
class vector {
    private:
        T* _b;
        T* _e;
    public:
        vector (const vector& rhs) {
            _b = new T[rhs.size()];
            _e = _b + rhs.size();
            copy(rhs._b, rhs._e, _b);}

        vector& operator = (const vector& rhs) {
            vector that(rhs);
            swap(_b, that._b);
            swap(_e, that._e);
/*
            if (this == &rhs)
               return *this;
            delete [] _b;
            _b = new T[rhs.size()];
            _e = _b + rhs.size();
            copy(rhs._b, rhs._e, _b);
*/
            return *this;}

        ~vector () {
            delete [] _b;}

int main () {
    int s = ...
    T v(...);          // T(...), once
    vector<T> x(s, v); // T(), s times; =(T), s times

    // real vector
    vector<T> x(s, v); // T(T), s times

template <typename T>
class vector {
    private:
        allocator<T> _x;
        T* _b;
        T* _e;
    public:
        vector (int s, const T& v) {
            _b = _x.allocate(s); // nothing of T
            _e = _b + s;
            T* b = _b;
            while (b != _e) {
                //new (b) T(v);   // placement new, T(T), s times
                _x.construct(b, v);
                ++b;}

        ~vector () {
            delete [] _b; // undefined
            T* b = _b;
            while (b != _e) {
                //b->~T();
                _x.destroy(b);
                ++b;}
            _x.deallocate(_b);}






































