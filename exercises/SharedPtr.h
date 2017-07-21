// -----------
// SharedPtr.h
// -----------

#ifndef SharedPtr_h
#define SharedPtr_h

#include <cassert>   // assert
#include <algorithm> // swap
#include <memory>    // default_delete

template <typename T>
class my_shared_ptr {
    public:
        using element_type = T;

    private:
        struct deleter {
            virtual      ~deleter ()         {}
            virtual void destroy  (T*) const = 0;};

        template <typename D = std::default_delete<T>>
        struct deleter_impl : deleter {
            D _d;

            deleter_impl (D d = D()) :
                    _d (d)
                {}

            virtual void destroy (T* p) const {
                _d(p);}};

        T*       _p;
        deleter* _q;
        int*     _c;

    public:
        explicit my_shared_ptr (T* p) :
                _p (p),
                _q ((p == nullptr) ? nullptr : new deleter_impl<>()),
                _c ((p == nullptr) ? nullptr : new int(1))
            {}

        template <typename D>
        explicit my_shared_ptr (T* p, D d) :
                _p (p),
                _q ((p == nullptr) ? nullptr : new deleter_impl<D>(d)),
                _c ((p == nullptr) ? nullptr : new int(1))
            {}

        my_shared_ptr (const my_shared_ptr& rhs) :
                _p (rhs._p),
                _q (rhs._q),
                _c (rhs._c) {
            if (_c != nullptr)
                ++*_c;}

        my_shared_ptr& operator = (const my_shared_ptr& rhs) {
            my_shared_ptr that(rhs);
            swap(that);
            return *this;}

        ~my_shared_ptr () {
            if (use_count() == 1) {
                _q->destroy(_p);
                delete _q;
                delete _c;}
            else if (_c != nullptr)
                --*_c;}

        T* get () const {
            return _p;}

        void swap (my_shared_ptr& that) {
            std::swap(_p, that._p);
            std::swap(_q, that._q);
            std::swap(_c, that._c);}

        int use_count () const {
            if (_c != nullptr)
                return *_c;
            return 0;}};

#endif // SharedPtr_h
