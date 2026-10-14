// Exercise 3: the same sum with "omp parallel for". S is shared and unprotected,
// so this version has a DATA RACE (fixed in Lab 04).
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define N 10000000L

int main(void) {
    double S = 0.0;
    double tstart = omp_get_wtime();

    #pragma omp parallel for
    for (long i = 1; i <= N; i++)
        S += (double)i - (double)i * i + sqrt(2.0 * (i + 1));

    double tcalc = omp_get_wtime() - tstart;
    printf("parallel: threads = %2d, S = %.6e, time = %f s\n", omp_get_max_threads(), S, tcalc);
    return 0;
}
