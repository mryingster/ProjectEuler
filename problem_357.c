// -*- compile-command: "gcc -std=c99 -o problem_357 problem_357.c -Wall ceuler.c -lm -O3" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

bool isPrimeGen(int n)
{
    for (int d=1; d<=sqrt(n); d++)
        if (n % d == 0)
            if (isPrime(d+(n/d)) != true)
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

    // Now solve
    int candidate = 0;
    for (int n=0; candidate<limit; n++)
    {
        candidate = 4 * n + 2;             // Pattern 1
        if (isPrime(candidate + 1))        // Pattern 2
        {
            if (isPrime(candidate/2+2))    // Pattern 3
            {
                if (isPrimeGen(candidate)) // Verify number by brute force
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
