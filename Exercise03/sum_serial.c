// Exercise 3: S = sum_{i=1..N} [ i - i^2 + sqrt(2 * (i + 1)) ], N = 10,000,000 (serial)
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define N 10000000L

int main(void) {
    double S = 0.0;
    double tstart = omp_get_wtime();

    for (long i = 1; i <= N; i++)
        S += (double)i - (double)i * i + sqrt(2.0 * (i + 1));

    double tcalc = omp_get_wtime() - tstart;
    printf("serial:   S = %.6e, time = %f s\n", S, tcalc);
    return 0;
}
