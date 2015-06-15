// -*- compile-command: "gcc -std=c99 -o problem_179 problem_179.c ceuler.c -Wall -lm -O3" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 179:\n"
           "Find the number of integers 1 < n < 10^7 for which n and n + 1 have the same number of divisors.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int limit = 10000000;
    int *factors = malloc(limit*sizeof(int));
    int result = 0;
    bool debug = false;

    // Count all the factors for all numbers under limit
    for (int i=2; i<limit; i++)
    {
        for (int n=1; n*i<limit; n++)
        {
            factors[n*i]++;
        }
    }

    // Debug - print computed factors
    if (debug == true)
    {
        for (int i=0; i<limit; i++)
            printf("%d: %d\n", i, factors[i]+1);
        printf("\n");
    }

    // Count consecutive numbers that are equal
    for (int i=2; i<limit-1; i++)
        if (factors[i] == factors[i+1])
            result++;

    printf("%d\n", result);
    printElapsedTime(start);

    free(factors);
    return 0;
}
