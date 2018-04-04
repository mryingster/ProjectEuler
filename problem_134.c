// -*- compile-command: "gcc -std=c99 -o problem_134 problem_134.c ceuler.c -Wall -lm -O3" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "ceuler.h"

void primeGen(unsigned long long **primes, int n, unsigned long long *len, bool debug)
{
    unsigned long long max = pow(10, n)+5;
    unsigned long long min = 3;
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

int main()
{
    printf("Project Euler - Problem 134:\n"
           "For every pair of consecutive primes, p2 > p1, there exist values of n for which the last digits are formed by p1 and n is divisible by p2. Let S be the smallest of these values of n. Find the sum of S for every pair of consecutive primes with 5 <= p1 <= 1000000\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    bool debug = false;
    int j = 6; //Number of digits

    // Get primes within digit range
    unsigned long long nprimes = 2;
    unsigned long long *primes = malloc(nprimes*sizeof(unsigned long long));
    if (!primes) err(1, "Unable to malloc primes array.");
    primeGen(&primes, j, &nprimes, debug);

    if (debug == true)
    {
        printf("\n%llu Primes generated\n", nprimes);
        printElapsedTime(start);
        for (int i=0; i<nprimes; i++) {
            printf("%d %llu\n", i, primes[i]);
        }
    }

    // Do our calculations!
    unsigned long long sum = 0;
    for (int a=0; a<nprimes-1; a++){
        int b = a + 1;
        int l = numberOfDigits(primes[a]);
        unsigned long long  mask = pow(10, l);
        unsigned long long S = primes[b];

        while (primes[a] != S % mask) {
            S += primes[b];
        }

        sum += S;
    }

    printf("Sum: %llu\n", sum);
    printElapsedTime(start);

    free(primes);
    return 0;
}
