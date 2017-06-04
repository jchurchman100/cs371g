// ----------
// Fri, 2 Jun
// ----------

/*
Canvas: for grades, for quizzes and tests, for communication of a personal
Piazza: for discussion

to develop code

1. the CS lab machines
2. configure your own machine
3. use a Docker image

writing tests

1. gives you clarity about what your code should do
2. use the test to validate the code
3. in the future you can use tests as regression tests

for tests to be useful

1. you have to run them
2. have to have good coverage

continuous integration

1. tests will be automatically
2. makes clear what your code and tests might depend on
*/

int i = 2;
cout << i; // output i, which is 2

/*
type of i    is int
type of cout is ostream
*/

int i = 2;
int j = 3;
int k = (i << j);
cout << i;        // 2
cout << j;        // 3
cout << k;        // output 16

cout << i << j;

/*
operator overloading
new meaning to an operator
*/

i + j * k
i - j - k
i = j = k

/*
unary
    -, *, ++, --
binary
    +, -, /, *
ternary
    ? :
n-ary
    ()
*/

int i = 2;
int j = 3;
int k = (i << j); // doesn't change i or j
k = (2 << j);
k = (2 << 3);
i = 4;
2 = 4;            // not ok

int i = 2;
int j = 3;
i <<  j;   // not ok
i <<= j;   // changes i, but not j
i <<= 3;
2 <<= 3;   // not ok

/*
bit-shifting
<<  takes two r-values
>>  takes two r-values

<<= takes an l-value and an r-value
>>= takes an l-value and an r-value
*/

k = (i <<  j); // ok in C, C++, Java, Python
(i << j) = k;  // not ok

k = (i <<= j); // ok in C, C++, Java, not Python
(i <<= j) = k; // ok in C++, not in C, Java, Python

/*
<<  returns a  r-value
<<= returns an l-value

1. can't invent a token, like ,,,
2. meaning of the operator on built-in types is unchangeable
3. can define an operator on a user-defined type
4. can't change precedence
5. can't change associativity
6. can't overload ., ?:, ,
7. can't change arity (no. of arguments)
8. we CAN change the r-value/l-value nature of the arguments and the return
*/

cout << i << j;
(cout << i) << j;
cout << flush;
cout << 2;

/*
output's << takes an l-value and an r-value
output's << returns an l-value

cin is of type istream
*/

int i;
cin >> i >> j;
(cin >> i) >> j;

/*
input's >> takes l-value and l-value
input's >> returns an l-value
*/

// ---------
// Questions
// ---------

/*
What are the benefits of testing first?
What are the benefits of continuous integration?
What's the benefit of Docker?
When overloading an operator, what properties can be changed, what properties can not be changed?
What is an l-value, an r-value?
What is the l-value/r-value nature of the arguments and the return of int's << operator, int's <<= operator, ostream's << operator?
What is the l-value/r-value nature of the arguments and the return of int's >> operator, int's >>= operator, istream's >> operator?
*/
