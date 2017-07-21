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
        T* _p;
        D  _d;

    public:
        my_unique_ptr () :
                _p (nullptr),
                _d ()
            {}

        explicit my_unique_ptr (T* p) :
                _p (p),
                _d ()
            {}

        my_unique_ptr (T* p, D d) :
                _p (p),
                _d (d)
            {}

        my_unique_ptr (const my_unique_ptr&) = delete;

        my_unique_ptr (my_unique_ptr&& rhs) :
                _p (rhs.release()),
                _d (std::move(rhs._d))
            {}

        my_unique_ptr& operator = (const my_unique_ptr&) = delete;

        my_unique_ptr& operator = (my_unique_ptr&& rhs) {
            if (this == &rhs)
                return *this;
            reset(rhs.release());
             _d = std::move(rhs._d);
            return *this;}

        ~my_unique_ptr () {
            reset();}

        T* get () const {
            return _p;}

        T* release () {
            T* p = _p;
            _p = nullptr;
            return p;}

        void reset (T* p = nullptr) {
            if (_p != p) {
                if (_p != nullptr)
                    _d(_p);
                _p = p;}}

        void swap (my_unique_ptr& that) {
            std::swap(_p, that._p);
            std::swap(_d, that._d);}};

#endif // UniquePtr_h
