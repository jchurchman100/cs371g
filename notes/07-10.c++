// -----------
// Mon, 10 Jul
// -----------

T* a = new T[s];   // T(),  s times
fill(a, a + s, v); // =(T), s times

allocator<T> x;
T* a = x.allocate(s);        // nothing
for (int i = 0; i != s; ++i)
    x.construct(a + i, v);   // T(T), s times

vector<T> x(3, v);
vector<T> y(2, w);
x = y;
~T(), once
=(T), twice

T* a = new T[s]; // keyword new
...
delete [] a;

T* a = static_cast<T*>(operator new (s * sizeof(T)));
for (int i = 0; i != s; ++i)
    new (a + i) T(v);
...
delete [] a; // not ok
for (int i = 0; i != s; ++i)
    (a + i)->~T();
operator delete(a);

template <typename T, typename A = std::allocator<T>>
class vector {
    private:
        A _a;
    ...};

vector<T> x(s, v);

template <typename T, typename A = std::allocator<T>>
class list {
    private:
        class node {
            node* p;
            node* n;
            T     v;};

        A::rebind<node>::other _a; // allocator<node>
    ...};

list<T> x(s, v);

template <typename T>
struct allocator {
    template <typename U>
    struct rebind {
        using other = allocator<U>;};};

int main () {
    allocator<int>                        x; // allocator<int>
    allocator<int>::rebind<double>::other y; // allocator<double>

template <typename T, typename A = std::allocator<T>>
class deque {
    private:

        A _a;                     // allocator<T>
        A::rebind<T*>::other _a2; //
    ...};

list<T> x(s, v);

// ---------
// Questions
// ---------

/*
What is the advantage of using allocator in vector?
What is the advantage of letting the user specify the allocator type?
What is rebind? Why is it necessary?
*/
