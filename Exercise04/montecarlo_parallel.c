// Exercise 4: Monte Carlo Pi with OpenMP, 10,000,000 random points.
// Each thread has its own random seed (rand() itself is not thread-safe), but the
// counter "inside" is shared and unprotected, so this version has a DATA RACE (fixed in Lab 04).
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define POINTS 10000000L

int main(void) {
    long inside = 0;
    double tstart = omp_get_wtime();

    #pragma omp parallel
    {
        unsigned int seed = 12345 + 1000 * omp_get_thread_num();
        #pragma omp for
        for (long i = 0; i < POINTS; i++) {
            double x = (double)rand_r(&seed) / RAND_MAX;
            double y = (double)rand_r(&seed) / RAND_MAX;
            if (x * x + y * y <= 1.0)
                inside++;             // shared counter, updated by every thread
        }
    }
    double pi = 4.0 * inside / POINTS;

    double tcalc = omp_get_wtime() - tstart;
    printf("parallel: threads = %2d, pi = %.6f, inside = %ld, time = %f s\n",
           omp_get_max_threads(), pi, inside, tcalc);
    return 0;
}
