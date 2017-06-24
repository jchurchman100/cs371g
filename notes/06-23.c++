// -----------
// Wed, 23 Jun
// -----------

/*
iteration story
transform (map)
accumulate (reduce)
*/

int i = 2; // initialization (construction)
vs.
i = 2;     // assignment

/*
the only difference between struct and class is
the default access directive
public for struct
private for class

what do you get for free
default constructor
copy constructor
copy assignment operator
destructor

any of the four can be turned off with = delete
default can be turned off with the definition of any constructor
copy assignment will be turned off if you can contain non-assignable members
any of the four will be turned off if a parent or a member has turned off

method == member function
*/

template <typename T>
class range_iterator {
    friend bool operator == (const range_iterator& lhs, const range_iterator& rhs) {
        return (lhs.val == rhs.val);}

    private:
        T val;

    public:
//      range_iterator (const T& v) { // T's default constructor
//           val = v;}                // T's copy assignment

        range_iterator (const T& v) : // member initialization list
            val (v)                   // T's copy constructor
            {}

        range_iterator (const range_iterator& rhs) :
            val (rhs.val)
            {}

        range_iterator& operator ++ () {
            ++val;
            return *this;}

        range_iterator operator ++ (int) {
            range_iterator tmp(*this);
            ++*this;
            return tmp;}

        const T& operator * () const {
            return val;}

//        bool operator == (const range_iterator& rhs) const {
//            return (val == rhs.val);}
        };

int main () {
    range_iterator<int> b = 2; // needs a non-explicit constructor
    range_iterator<int> x(2);
    range_iterator<int> e = 2;
    cout << (b == e);          // true
    cout << b.operator==(e);   // true, don't want this
    cout << operator==(b, e);  // true, want this instead

    cout << (b == 2);
    cout << (2 == b); // not ok

// ---------
// Questions
// ---------

/*
What's the benefit of the member initialization list?
Under what circumstances is the default constructor not auto-generated?
Under what circumstances is the copy constructor not auto-generated?
Under what circumstances is the copy assignment not auto-generated?
Under what circumstances is the destructor not auto-generated?
What's the benefit of operator==() being a function instead of a method?
What turns off a one-arg constructor from being a type converter?
Implement transform() (unary and binary).
Implement accumulate().
*/
