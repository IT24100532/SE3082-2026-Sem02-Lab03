# Build on Linux (AWS EC2 or Docker): make        Run all timings: make run
CC = gcc
CFLAGS = -Wall -O2 -fopenmp
PROGS = bin/pi_serial bin/pi_parallel bin/sum_serial bin/sum_parallel bin/montecarlo_serial bin/montecarlo_parallel
THREADS = 1 2 4 8 16

all: $(PROGS)

bin/%: Exercise01/%.c | bin
	$(CC) $(CFLAGS) $< -o $@ -lm
bin/%: Exercise02/%.c | bin
	$(CC) $(CFLAGS) $< -o $@ -lm
bin/%: Exercise03/%.c | bin
	$(CC) $(CFLAGS) $< -o $@ -lm
bin/%: Exercise04/%.c | bin
	$(CC) $(CFLAGS) $< -o $@ -lm

bin:
	mkdir -p bin

run: all
	@echo "== Exercise 1/2: Pi"; ./bin/pi_serial; for t in $(THREADS); do OMP_NUM_THREADS=$$t ./bin/pi_parallel; done
	@echo "== Exercise 3: S"; ./bin/sum_serial; for t in $(THREADS); do OMP_NUM_THREADS=$$t ./bin/sum_parallel; done
	@echo "== Exercise 4: Monte Carlo Pi"; ./bin/montecarlo_serial; for t in $(THREADS); do OMP_NUM_THREADS=$$t ./bin/montecarlo_parallel; done

clean:
	rm -rf bin
