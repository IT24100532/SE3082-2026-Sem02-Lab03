// Exercise 4: Pi with the Monte Carlo method (serial), 10,000,000 random points.
// Based on the method in https://www.geeksforgeeks.org/dsa/estimating-value-pi-using-monte-carlo/
// A point (x, y) in the unit square is inside the quarter circle if x^2 + y^2 <= 1,
// so pi ~= 4 * (points inside) / (all points).
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define POINTS 10000000L

int main(void) {
    long inside = 0;
    unsigned int seed = 12345;
    double tstart = omp_get_wtime();

    for (long i = 0; i < POINTS; i++) {
        double x = (double)rand_r(&seed) / RAND_MAX;
        double y = (double)rand_r(&seed) / RAND_MAX;
        if (x * x + y * y <= 1.0)
            inside++;
    }
    double pi = 4.0 * inside / POINTS;

    double tcalc = omp_get_wtime() - tstart;
    printf("serial:   pi = %.6f, inside = %ld, time = %f s\n", pi, inside, tcalc);
    return 0;
}
