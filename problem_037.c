// -*- compile-command: "gcc -o problem_037 problem_037.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ceuler.h>

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
    int index = 0;
    int primes[500000] = {0};
    int primeCount = 0;
    unsigned long long sum = 0;

    printf("Project Euler - Problem 37:\n"
           "Find the sum of the only eleven primes that are both truncatable from left to right and right to left.\n\n");

    // Find primes
    for (index=2 ; index<800000 ; index++)
        if (isPrimeOpt(index, primes) == true)
        {
            primes[primeCount]=index;
            primeCount++;
        }

    // Go through each prime and truncate
    for (index=4 ; index<primeCount ; index++)
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
            //printf("%d\n", primes[index]); // DEBUG - Print valid primes
            sum += primes[index];
        }
    }

    printf("Sum of primes: %llu\n", sum);

    return 0;
}
