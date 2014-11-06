// -*- compile-command: "gcc -o problem_007 problem_007.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    int primeCount    = 0;
    int candidate     = 1;
    int primes[10002] = {0};

    printf("Project Euler - Problem 7:\n"
           "What is the 10,001st prime number?\n\n");

    while ( primeCount < 10001 )
        if ( isPrimeOpt(++candidate, primes) )
            primes[primeCount++] = candidate;

    printf("10,001st prime: %d\n", candidate);

    return 0;
}
