// -*- compile-command: "gcc -std=c99 -o problem_357 problem_357.c -Wall ceuler.c -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

bool isPrimeGen(int n)
{
    for (int d=1; d<n+1/2; d++)
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

    for (int n=2; n<=limit; n+=2)
        if (isPrimeGen(n))
        {
            sum += n;
            if (debug == true)
            {
                printf("%d, %llu\r", n, sum);
                fflush(stdout);
            }
        }

    printf("Sum: %llu     \n", sum);
    printElapsedTime(start);

    return 0;
}
