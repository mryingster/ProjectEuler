// -*- compile-command: "gcc -std=c99 -o problem_124 problem_124.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

int compare(const void *a, const void *b)
{
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return *ia - *ib;
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

    const int limit = 100001;
    int rad[100000] = {};
    int primes[100000] = {};
    int pindex = 0;
    bool debug = false;

    rad[1] = 1;
    for (int n=2; n<limit; n++)
    {
        if (isPrime(n))
        {
            rad[n] = n;
            primes[pindex++] = n;
        }
        else
        {
            rad[n] = factorProduct(n, primes, pindex);
        }
    }

    // Duplicate array for later
    int rad2[100000] = {};
    for (int i=0; i<limit; i++)
        rad2[i] = rad[i];

    // QSORT them here...
    qsort(rad, limit, sizeof(rad[0]), compare);

    // Find offset (number of elements preceeding with same value)
    int answer = rad[10000];
    int offset = 0;
    while (rad[10000-offset] == answer)
        offset++;

    // Go back to original list to find index of answer from sorted list
    int finalAnswer = 0;
    for (int i=0; i<limit; i++)
    {
        if (rad2[i] == answer)
            offset--;
        if (offset == 0)
        {
            finalAnswer = i;
            break;
        }
    }

    // DEBUG
    if (debug == true)
        for (int n=1; n<limit; n++)
            printf("%d, %d\n", n, rad2[n]);

    printf("%d\n", finalAnswer);

    return 0;
}
