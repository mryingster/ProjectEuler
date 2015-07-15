// -*- compile-command: "gcc -std=c99 -o problem_037 problem_037.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "ceuler.h"

bool inArray(int value, int *array)
{
    int index = 0;
    while (array[index] <= value)
        if (array[index++] == value)
            return true;

    return false;
}

int main()
{
    printf("Project Euler - Problem 37:\n"
           "Find the sum of the only eleven primes that are both truncatable from left to right and right to left.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int primes[100000] = {0};
    int nprimes = sizeof(primes)/sizeof(int);
    unsigned long long sum = 0;
    bool debug = false;

    // Find primes
    primeSieve(primes, nprimes);

    // Go through each prime and truncate
    for (int index=4 ; index<nprimes ; index++)
    {
        bool truncatable = true;
        int leftTruncCount = 0;

        // Make sure number 2 < digit numbers contain no even digits
        int truncate = primes[index];

        if (truncate > 100)
            while ((truncate/=10) > 0)
                if ( truncate % 2 == 0)
                {
                    truncatable = false;
                    break;
                }
        if (truncatable == false) continue;

        // Truncate from right
        truncate = primes[index];
        while ((truncate /= 10) > 0)
        {
            leftTruncCount++;
            if (inArray(truncate, primes) != true)
            {
                truncatable = false;
                break;
            }
        }
        if (truncatable == false) continue;

        // Truncate from left
        truncate = primes[index];
        while (leftTruncCount > 0)
        {
            truncate = truncate % (int)pow(10, leftTruncCount);
            leftTruncCount--;

            if (inArray(truncate, primes) != true)
            {
                truncatable = false;
                break;
            }
        }

        // Check if prime is eligible
        if (truncatable == true)
        {
            if (debug == true)
                printf("%d\n", primes[index]);
            sum += primes[index];
        }
    }

    printf("Sum of primes: %llu\n", sum);
    printElapsedTime(start);

    return 0;
}
