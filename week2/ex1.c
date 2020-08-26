#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int i;
    float f;
    double d;
    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;
    printf("i is: %d", i);
    printf(", and size of i is: %lu", sizeof(i));
    printf("\nf is: %f", f);
    printf(", and size of f is: %lu", sizeof(f));
    printf("\nd is: %lf", d);
    printf(", and size of d is: %lu", sizeof(d));
    return 0;
}
