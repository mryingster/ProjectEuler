// -*- compile-command: "gcc -std=c99 -o problem_012 problem_012.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int findDivisors(int input, int *primes, int nprimes)
{
    int index, count=1;
    int primeCount[nprimes];
    for (index=0; index<nprimes; index++)
        primeCount[index] = 0;

    // Prime factorization
    while (input != 1)
        for (index=0; index<nprimes; index++)
            if (input % primes[index] == 0)
            {
                input = input / primes[index];
                primeCount[index]++;
            }

    // Convert prime factorization to divisors
    for (index=0; index<nprimes; index++)
        if (primeCount[index] > 0)
            count *= (primeCount[index]+1);

    return count;
}

int main()
{
    printf("Project Euler - Problem 12:\n"
           "What is the value of the first triangle number to have over five hundred divisors?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int index=0, triangle=0, divisors=0;
    int nprimes = 1500;
    int primes[nprimes];
    primeSieve(primes, nprimes);

    // Calculate Triangles
    index = 0;
    while(index<1000000)
    {
        index++;
        triangle += index;

        // Skip numbers not divisible by 3 or 5
        if ( (triangle % 3 != 0) || (triangle % 5 != 0) )
            continue;
        divisors = findDivisors(triangle, primes, nprimes);

        if (divisors > 500)
            break;
    }

    printf("Triangle Value: %d, Divisors: %d\n", triangle, divisors);
    printElapsedTime(start);

    return 0;
}
