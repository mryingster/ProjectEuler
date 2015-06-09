// -*- compile-command: "gcc -std=c99 -o problem_357 problem_357.c -Wall ceuler.c -lm -O3" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

bool isPrimeGen(int n, bool *primes)
{
    for (int d=1; d<=sqrt(n); d++)
        if (n % d == 0)
            if (primes[d+n/d] != true)
                return false;

    return true;
}

int main()
{
    printf("Project Euler - Problem 357:\n"
           "Find the sum of all positive integers n not exceeding 100,000,000 such that for every divisor d of n, d+n/d is prime.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    const int limit = 100000000;
    unsigned long long sum = 1;
    bool debug = false;

    // Generate primes using sieve
    bool *primes = malloc(limit*sizeof(bool));
    for (int i=2; i<limit; i++)
        primes[i] = true;
    primes[0] = false;
    primes[1] = false;

    for (int i=2; i<limit; i++)
        if (primes[i] == true)
        {
            int n = 2;
            while (n*i < limit)
                primes[i*n++] = false;
        }

    if (debug == true)
    {
        printf("Prime table generated.\n");
        printElapsedTime(start);
    }

    // Now solve problem
    int candidate = 0;
    for (int n=0; candidate<limit; n++)
    {
        candidate = 4 * n + 2;                 // Pattern 1
        if (primes[candidate + 1] == true)     // Pattern 2
        {
            if (primes[candidate/2+2] == true) // Pattern 3
            {
                if (isPrimeGen(candidate, primes)) // Verify number by brute force
                {
                    sum += candidate;
                    if (debug == true)
                    {
                        printf("%d, %llu\r", candidate, sum);
                        fflush(stdout);
                    }
                }
            }
        }
    }

    printf("Sum: %llu     \n", sum);
    printElapsedTime(start);

    return 0;
}
