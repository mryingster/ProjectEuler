// -*- compile-command: "gcc -std=c99 -o problem_187 problem_187.c ceuler.c -Wall -lm -O3" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 187:\n"
           "How many composite integers, n < 10^8, have precisely two, not necessarily distinct, prime factors?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    // Get primes
    int primeLimit = 6587000;
    int limit = 100000000;
    int *primes = malloc(primeLimit*sizeof(int));
    primeSieve(primes, primeLimit);

    int result = 0;
    bool debug = false;

    // Count all the factors for all numbers under limit
    for (int i=0; primes[i]<limit; i++)
    {
        for (int n=i; (unsigned long long)primes[n]*(unsigned long long)primes[i]<limit; n++)
        {
            if (debug == true)
                printf("%d * %d = %d\n", primes[i], primes[n], primes[i]*primes[n]);
            result++;
        }
    }

    printf("%d\n", result);
    printElapsedTime(start);

    free(primes);
    return 0;
}
