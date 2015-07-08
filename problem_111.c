// -*- compile-command: "gcc -std=c99 -o problem_111 problem_111.c ceuler.c -Wall -lm -O3" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "ceuler.h"

void primeGen(unsigned long long **primes, int n, unsigned long long *len, bool debug)
{
    unsigned long long max = pow(10, n)-1;
    unsigned long long min = pow(10, n-1);
    unsigned long long index = 0;
    bool *sieve = malloc(max*sizeof(bool));

    for (unsigned long long i=2; i<max; i++) sieve[i] = true;
    sieve[0] = false;
    sieve[1] = false;

    if (debug == true)
        printf("Min: %llu, Max: %llu\n", min, max);

    // Find primes up until MAX number size
    for (unsigned long long i=2; i<max; i++)
        if (sieve[i] == true)
        {
            if (debug == true)
            {
                printf("\r%llu", i);
                fflush(stdout);
            }

            // Only record primes if they are larger than MIN number size
            if (i > min)
            {
                (*primes)[index++] = i;
                // Realloc if necessary
                if (index == *len)
                {
                    *len *= 2;
                    if (debug == true)
                        printf("\nRemallocing! Length: %llu, Size: %llu bytes\n",
                               *len, *len*sizeof(unsigned long long));
                    *primes = realloc(*primes, *len*sizeof(unsigned long long));
                    if (!primes) err(1, "Unable to relloc primes array.");
                }
            }

            unsigned long long t = 2*i;
            while (t < max)
            {
                sieve[t] = false;
                t += i;
            }
        }

    *len = index;
    free(sieve);
}

void solve(int n, int d, int *M, int *N, unsigned long long *S, unsigned long long *primes, unsigned long long nprimes)
{
    // Find M - Number of digits that should match 'd'
    *M = n;

    // Find N - Number of primes with M d's
    // Find S - the sum of Ns
    while ((*M)--)
    {
        for (int i=0; i<nprimes; i++)
        {
            unsigned long long tmp = primes[i];
            int dig = 0;
            while (tmp > 0)
            {
                if (tmp % 10 == d)
                    dig++;
                tmp /= 10;
            }
            if (dig == *M)
            {
                (*N)++;
                *S += primes[i];
            }
        }
        if (*N > 0) break;
    }
}

int main()
{
    printf("Project Euler - Problem 111:\n"
           "Find the sum of all S(10, d) numbers, where S is the sum of primes, 10 digits in length, who has the maximum number of repeated digits for each digits, d.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    bool debug = false;
    int j = 10; // Number of digits

    // Get primes withing digit range
    unsigned long long nprimes = 2;
    unsigned long long *primes = malloc(nprimes*sizeof(unsigned long long));
    if (!primes) err(1, "Unable to malloc primes array.");
    primeGen(&primes, j, &nprimes, debug);

    if (debug == true)
    {
        printf("\n%llu Primes generated\n", nprimes);
        printElapsedTime(start);
    }

    // Solve M, N, and S for each digit
    unsigned long long sum = 0;
    for (int d=0; d<10; d++)
    {
        int M=0, N=0;
        unsigned long long S=0;
        solve(j, d, &M, &N, &S, primes, nprimes);
        if (debug == true)
            printf("%d, %d, %d, %llu\n", d, M, N, S);
        sum += S;
    }

    printf("Sum: %llu\n", sum);
    printElapsedTime(start);

    free(primes);
    return 0;
}
