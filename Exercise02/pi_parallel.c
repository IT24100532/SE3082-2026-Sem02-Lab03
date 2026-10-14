// Exercise 2: Pi from Exercise 1, parallelised by putting "omp parallel for" on the loop.
// sum is shared by all threads and nothing protects it, so this version has a DATA RACE
// (fixed in Lab 04 with critical and atomic sections).
#include <stdio.h>
#include <omp.h>

#define N 100000000L

int main(void) {
    double sum = 0.0;
    double tstart = omp_get_wtime();

    #pragma omp parallel for
    for (long i = 1; i <= N; i++) {
        double x = (i - 0.5) / N;
        sum += 1.0 / (1.0 + x * x);   // every thread reads and writes the same sum
    }
    double pi = 4.0 * sum / N;

    double tcalc = omp_get_wtime() - tstart;
    printf("parallel: threads = %2d, pi = %.15f, error = %.2e, time = %f s\n",
           omp_get_max_threads(), pi, pi - 3.141592653589793, tcalc);
    return 0;
}
