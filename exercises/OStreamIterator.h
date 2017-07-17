// -----------------
// OStreamIterator.h
// -----------------

#ifndef OStreamIterator_h
#define OStreamIterator_h

#include <iostream>  // ostream
#include <iterator>  // iterator, output_iterator_tag

template <typename T, typename C = char>
class my_ostream_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void> {
    public:
/*
        typedef std::output_iterator_tag iterator_category;
        typedef void                     value_type;
        typedef void                     difference_type;
        typedef void                     pointer;
        typedef void                     reference;
*/
    private:
              std::ostream& _o;
        const C*            _d;

    public:
        my_ostream_iterator (std::ostream& o, const C* d = 0) :
                _o (o),
                _d (d)
            {}

        // Default copy, destructor, and copy assignment.
        // my_ostream_iterator (const my_ostream_iterator&);
        // ~my_ostream_iterator ();
        // my_ostream_iterator& operator = (const my_ostream_iterator&);

        my_ostream_iterator& operator = (const T& v) {
            _o << v;
            if (_d)
                _o << _d;
            return *this;}

        my_ostream_iterator& operator * () {
            return *this;}

        my_ostream_iterator& operator ++ () {
            return *this;}

        my_ostream_iterator operator ++ (int) {
            return *this;}};

#endif // OStreamIterator_h
