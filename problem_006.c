// -*- compile-command: "gcc -std=c99 -o problem_006 problem_006.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 6:\n"
           "Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int sumsquares = 0, squaresums = 0;

    for (int n=1 ; n<=100 ; n++)
    {
        squaresums += n;
        sumsquares += n * n;
    }

    squaresums *= squaresums;

    //printf("%d %d\n", squaresums, sumsquares); // DEBUG

    printf("Difference: %d\n", squaresums-sumsquares);
    printElapsedTime(start);

    return 0;
}

