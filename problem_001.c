// -*- compile-command: "gcc -std=c99 -o problem_001 problem_001.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 1:\n"
           "Find the sum of all the multiples of 3 or 5 below 1000.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int total = 0;

    for ( int number=0 ; number<1000 ; number++ )
        if ( number % 3 == 0 || number % 5 == 0 )
                total += number;

    printf("Sum: %d\n", total);
    printElapsedTime(start);

    return 0;
}

