// -*- compile-command: "gcc -std=c99 -o problem_043 problem_043.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"
#include <stdbool.h>

bool divisibility( unsigned long number)
{
    int primes[7] = {2, 3, 5, 7, 11, 13, 17};
    int index = 0, divisor = 1000000, tmp = 0;

    for (index = 0; index < 7; index++)
    {
        tmp = number / divisor % 1000;
        if (tmp % primes[index] != 0)
            return false;
        divisor /= 10;
    }
    return true;
}

int main()
{
    printf("Project Euler - Problem 43:\n"
           "Find the sum of all 0 to 9 pandigital numbers with the sub-string divisibility property.\n\n");

    unsigned long number = 1406357289; // Given smallest number
    unsigned long long total  = 0;

    while (number < 9876543210)
    {
        if ( isPandigital(number) == true )
            if ( divisibility(number) == true )
                printf("%lu\n", number);
                total += number;
        number += 9; // Pandigitals appear to always be multiple of 9 apart
    }

    printf("Sum of numbers: %llu\n", total);
    return 0;
}
