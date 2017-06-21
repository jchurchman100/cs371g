// -----------
// Wed, 21 Jun
// -----------

/*
generics
specialization
*/

vector<int>  x(10000);
vector<bool> y(10000);

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

template <typename T>
class list {
    public:
        class iterator {
            public:
                using iterator_category = bidirectional_iterator_tag;
                using difference_type   = ptrdiff_t;
        ...
    private:
        ...};

template <typename I>
struct iterator_traits {
    using difference_type = I::difference_type;};

template <typename T>
struct iterator_traits<T*> {
    using difference_type = ptrdiff_t;};

template <typenane FI, typename T>
iterator_traits<II>::difference_type count (II b, II e, const T& v) {
    iterator_traits<II>::difference_type c;
    while (b != e) {
        if (*b == v)
            ++c;
        ++b;}
    return c;}

template <typename I>
struct iterator_traits {
    using iterator_category = I::iterator_category;
    using difference_type   = I::difference_type;};

template <typename T>
struct iterator_traits<T*> {
    using iterator_category = random_access_iterator_tag;
    using difference_type   = ptrdiff_t;};

template <typename RI>
void reverse (RI b, RI e, random_access_iterator_tag) {
    while (b < --e) {
        swap(*b, *e);
        ++b;}}

template <typename BI>
void reverse (BI b, BI e, bidirectional_iterator_tag) {
    while ((b != e) && (b != --e)) {
        swap(*b, *e);
        ++b;}}

template <typename I>
void reverse (I b, I e) {
    return reverse(b, e, iterator_traits<I>::iterator_category());

// ---------
// Questions
// ---------

/*
What is specialization?
Why is vector<bool> a specialization?
What is ptrdiff_t?
What is difference_type?
What is iterator_traits?
Why is iterator_traits<T*> a specialization?
What are iterator_tags? Why do they in inherit from each other?
What is count()'s return type?
What is the definition of reverse() with a random access iterator?
What is the definition of reverse() with a bidirectional iterator?
How does compile-time dispatch work?
*/
