// -*- compile-command: "gcc -std=c99 -o problem_007 problem_007.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 7:\n"
           "What is the 10,001st prime number?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int primeCount    = 0;
    int candidate     = 1;

    while (primeCount < 10001)
        if (isPrime(++candidate))
            primeCount++;

    printf("10,001st prime: %d\n", candidate);
    printElapsedTime(start);

    return 0;
}
