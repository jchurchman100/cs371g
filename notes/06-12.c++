// -----------
// Mon, 12 Jun
// -----------

/*
root mean squared error

set of values that are the predictions
set of values that are the actuals

1. set of differences (errors)
2. square the differences
3. take the mean
4. take the square root

all caches MUST use Boost Serialization

necessary cache
    cache of the answers
    map of map of ratings
    array of may of ratings

possible caches
    find the subset of movies mentioned in probe.txt
    for each of those movies what's the average rating

    find the subset of customers mentioned in probe.txt
    for each of those customers what's the average rating
*/

void f (int v) {
    ++v;}

void g (int* p) {
//    ++p;
    ++*p;}

void h (int& r) {
//    ++*r;}
    ++r;}

int main () {
    int i = 2;
    f(i);
    cout << i; // 2

    int j = 3;
    g(j);      // not ok
    g(&j);
    cout << j; // 4

    int k = 4;
    h(&k);     // not ok
    h(k);
    cout << k; // 5

// ---------
// Questions
// ---------

/*
What is RMSE?
What is BoostSerialization?
How do pass by value, by address, and by reference differ?
What is the l-value/r-value nature of int's + operator? += operator?
What is the l-value/r-value nature of int's pre-increment operator? Post-increment operator?
What is the nature of the following:
    int a[] = {2, 3, 4};
What is the nature of the following:
    const int a[] = {2, 3, 4};
*/
