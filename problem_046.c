// -*- compile-command: "gcc -std=c99 -o problem_046 problem_046.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

bool goldbach(const int composite, const int * primes, const int primeIndex)
{
    int pIndex;

    for (pIndex=0; pIndex < primeIndex; pIndex++)
    {
        int nIndex = 1;
        int conjecture = primes[pIndex] + 2 * pow(nIndex, 2);
        while (conjecture <= composite)
        {
            if (conjecture == composite) return true;
            conjecture = primes[pIndex] + 2 * pow(++nIndex, 2);
        }
    }

    return false;
}

int main()
{
    printf("Project Euler - Problem 46:\n"
           "What is the smallest odd, composite number that cannot be written as the sum of a prime and twice a square?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int primes[10000] = {};
    int primeIndex = 0;
    int composite = 1;

    while ( composite++ )
    {
        if (isPrime(composite) == true)
            primes[primeIndex++] = composite;
        else // is composite number
        {
            if (isEven(composite) == true) continue;
            if (goldbach(composite, primes, primeIndex) == false) break;
        }
    }

    printf("Smallest composite: %d\n", composite);
    printElapsedTime(start);

    return 0;
}
