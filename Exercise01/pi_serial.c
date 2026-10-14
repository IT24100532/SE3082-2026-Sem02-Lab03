// Exercise 1: serial Pi using pi/4 = (1/N) * sum_{i=1..N} 1 / (1 + ((i - 0.5) / N)^2)
#include <stdio.h>
#include <omp.h>

#define N 100000000L

int main(void) {
    double sum = 0.0;
    double tstart = omp_get_wtime();

    for (long i = 1; i <= N; i++) {
        double x = (i - 0.5) / N;
        sum += 1.0 / (1.0 + x * x);
    }
    double pi = 4.0 * sum / N;

    double tcalc = omp_get_wtime() - tstart;
    printf("serial:   pi = %.15f, error = %.2e, time = %f s\n", pi, pi - 3.141592653589793, tcalc);
    return 0;
}
