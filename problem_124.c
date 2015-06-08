// -*- compile-command: "gcc -std=c99 -o problem_124 problem_124.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

typedef struct rad rad;
struct rad{
    int n;
    int rad;
};

int compare(const void *a, const void *b)
{
    const rad *ia = (const rad *)a;
    const rad *ib = (const rad *)b;
    return ia->rad - ib->rad;
}

int factorProduct(int number, const int * primes, const int primeIndex)
{
    int count = 0;
    int product = 1;
    int pindex = 0;

    while (number > 1)
    {
        if (number % primes[pindex] == 0)
        {
            number /= primes[pindex];
            if (++count == 1)
                product *= primes[pindex];
        }
        else
        {
            pindex++;
            count = 0;
        }
    }
    return product;
}

int main()
{
    printf("Project Euler - Problem 124:\n"
           "Find the 10,000th n in a sorted list of rad(n) where rad(n) is the product of the distinct prime factors of n.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    const int limit = 100001;
    rad rad[100001] = {};
    int primes[100000] = {};
    int pindex = 0;
    bool debug = false;

    rad[1].n   = 1;
    rad[1].rad = 1;
    for (int n=2; n<limit; n++)
    {
        rad[n].n = n;
        if (isPrime(n))
        {
            rad[n].rad = n;
            primes[pindex++] = n;
        }
        else
        {
            rad[n].rad = factorProduct(n, primes, pindex);
        }
    }

    // QSORT them here...
    qsort(rad, limit, sizeof(rad[0]), compare);

    // DEBUG - Print structure
    if (debug == true)
        for (int n=1; n<limit; n++)
            printf("%d, %d\n", rad[n].n, rad[n].rad);

    printf("%d\n", rad[10000].n);
    printElapsedTime(start);

    return 0;
}
