// -----------
// Mon, 17 Jul
// -----------

/*
iterator adapters
*/

vector<int>                       x(10, 2);
vector<int>                       y;
back_insert_iterator<vector<int>> p(x);
copy(begin(x), end(x), back_inserter(y));

cout << 2;

template <typename T, typename C = char>
class ostream_iterator {
    private:
        C*        _p;
        ostream& _o;

    public:
        ostream_iterator (ostream& o, C* p = nullptr) :
            _o (o),
            _p (p)
            {}

        ostream_iterator& operator * () {
            return *this;}

        ostream_iteartor operator = (const T& v) {
            _o << v;
            if (_p)
                _o << *p;}

int i;
cin >> i;
if (cin)
    <succeeded>
if (!cin)
    <failed>

template <typename T>
class istream_iterator {
    friend bool operator == (const istream_iterator& lhs, const istream_iterator& rhs) {
        return (lhs._p == rhs._p);

    private:
        istream* _p;
        T        _v;

    public:
        istream_iterator () :
            _p (nullptr)
            {}

        istream_iterator (istream& in) :
            _p (&in)
            {++*this;}

        T operator * () {
            return _v;}

        istream_iterator& operator ++ () {
            assert(_p);
            if (!(*_p >> _v))
                _p = nullptr;
            return *this;}

string s("abc")
string t("abc")
s == t
s == "abc"
"abc" == s

// ---------
// Questions
// ---------

/*
What is ostream_iterator?
What is istream_iterator?
What happens when a read fails?
In what operator does istream_iterator read?
What is reverse_iterator?
What is the minimum requirement iterator for reverse_iterator?
*/
