// -*- compile-command: "gcc -std=c99 -o problem_108 problem_108.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

int divisors(unsigned long long n, int *p, int np)
{
    int count = 1;
    int pCount[np];
    for (int i=0; i<np; i++)
        pCount[i] = 0;

    // Prime factorization
    for (int i=0; i<np; i++)
        while (n % p[i] == 0)
        {
            n /= p[i];
            pCount[i] +=2;
        }

    // Convert prime factorization to divisors
    for (int i=0; i<np; i++)
        if (pCount[i] > 0)
            count *= (pCount[i]+1);

    return count + 1;
}

int main()
{
    printf("Project Euler - Problem 108:\n"
           "Given 1/x + 1/y = 1/n, what is the least value of n for which the number of ditinct solutions exceeds one-thousand?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int nprime = 7;
    int *primes = malloc(nprime*sizeof(int));
    primeSieve(primes, nprime);

    unsigned long long n = 2;
    bool debug = false;

    int d = 0;
    int limit = 1000;
    while (d/2 < limit)
    {
        n++;
        d = divisors(n, primes, nprime);
        if (debug == true)
            printf("%llu, %d\n", n, d);
    }

    printf("n=%llu\n", n);
    printElapsedTime(start);

    free(primes);
    return 0;
}
