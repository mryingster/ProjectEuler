// -*- compile-command: "gcc -std=c99 -o problem_002 problem_002.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 2:\n"
           "By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    const int limit = 4000000;
    int previousNum = 0, nextNum = 0, currentNum = 1;
    int total = 0;

    while (currentNum < limit)
    {
        nextNum = previousNum + currentNum;
        previousNum = currentNum;
        currentNum = nextNum;
        if ( currentNum % 2 == 0)
            total += currentNum;
    }

    printf("Sum: %d\n", total);
    printElapsedTime(start);

    return 0;
}
