// ------------
// UnitTests1.h
// ------------

#ifndef UnitTests1_h
#define UnitTests1_h

int cycle_length (int n) {
    assert(n > 0);
    int c = 0;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

#endif // UnitTests1_h
