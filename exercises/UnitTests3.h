// ------------
// UnitTests3.h
// ------------

#ifndef UnitTests3_h
#define UnitTests3_h

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

#endif // UnitTests3_h
