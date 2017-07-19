// -----------
// UniquePtr.h
// -----------

#ifndef UniquePtr_h
#define UniquePtr_h

#include <algorithm> // swap
#include <memory>    // default_delete
#include <utility>   // move

template <typename T, typename D = std::default_delete<T>>
class my_unique_ptr {
    public:
        using element_type = T;

    private:
        T* _p = nullptr;
        D  _d;

    public:
        explicit my_unique_ptr (T* p, D d = D()) :
                _p (p),
                _d (d)
            {}

        my_unique_ptr (const my_unique_ptr&) = delete;

        my_unique_ptr (my_unique_ptr&& rhs) :
                _d (std::move(rhs._d)) {
            std::swap(_p, rhs._p);}

        my_unique_ptr& operator = (const my_unique_ptr&) = delete;

        my_unique_ptr& operator = (my_unique_ptr&& rhs) {
            if (this == &rhs)
                return *this;
            my_unique_ptr that(std::move(rhs));
            swap(that);
            return *this;}

        ~my_unique_ptr () {
            _d(_p);}

        T* get () const {
            return _p;}

        void swap (my_unique_ptr& that) {
            std::swap(_p, that._p);
            std::swap(_d, that._d);}};

#endif // UniquePtr_h
