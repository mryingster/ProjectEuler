// -*- compile-command: "gcc -o problem_041 problem_041.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell

#include <stdio.h>
#include <stdbool.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 41:\n"
           "What is the largest n-digit pandigital prime that exists?\n\n");

    // Start with 7 digit number because the sums of 8 and 9 digit pandigital
    // numbers are divisible by 3, which precludes them from being prime.

    long number = 7654321;

    while ( number-- > 1 )
    {
        if ( isPandigital(number) == false) continue;
        if ( isPrime(number) == true) break;
    }

    printf("Largest Pandigital Prime: %ld\n", number);
    return 0;
}
