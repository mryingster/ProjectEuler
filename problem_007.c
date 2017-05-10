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

    int limit = 10001;
    int *primes = malloc(limit*sizeof(int));
    primeSieve(primes, limit);

    printf("%d\n", primes[limit-1]);
    printElapsedTime(start);

    return 0;
}
