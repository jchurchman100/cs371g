// -----------------
// IStreamIterator.h
// -----------------

#ifndef IStreamIterator_h
#define IStreamIterator_h

#include <iostream> // istream
#include <iterator> // input_iterator_tag, iterator

template <typename T>
class my_istream_iterator : public std::iterator<std::input_iterator_tag, T> {
    friend bool operator == (const my_istream_iterator& lhs, const my_istream_iterator& rhs) {
        return (lhs._is == rhs._is);}

    public:
/*
        typedef std::input_iterator_tag iterator_category;
        typedef T                       value_type;
        typedef std::ptrdiff_t          difference_type;
        typedef T*                      pointer;
        typedef T&                      reference;
*/
    private:
        std::istream* _is;
        T             _v;

    public:
        my_istream_iterator () :
                _is (0),
                _v  ()
            {}

        my_istream_iterator (std::istream& is) :
                _is (&is),
                _v  () {
            ++*this;}

        // Default copy, destructor, and copy assignment.
        // my_istream_iterator (const my_istream_iterator&);
        // ~my_istream_iterator ();
        // my_istream_iterator& operator = (const my_istream_iterator&);

        const T& operator * () const {
            return _v;}

        my_istream_iterator& operator ++ () {
            if (_is && !(*_is >> _v))
                _is = 0;
            return *this;}

        my_istream_iterator operator ++ (int) {
            my_istream_iterator x = *this;
            ++*this;
            return x;}};

#endif // IStreamIterator_h
