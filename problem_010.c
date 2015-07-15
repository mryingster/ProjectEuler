// -*- compile-command: "gcc -std=c99 -o problem_010 problem_010.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 10:\n"
           "Find the sum of all the primes below two million.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int limit = 2000000;
    int nprimes = 1.5 * limit / log(limit);    // Estimate number of primes under limit
    int *primes = malloc(nprimes*sizeof(int));
    unsigned long long sum = 0;

    primeSieve(primes, nprimes);

    for (int i=0; primes[i]<limit; i++)
        sum += primes[i];

    printf("Sum of primes: %llu\n", sum);
    printElapsedTime(start);

    free(primes);
    return 0;
}
