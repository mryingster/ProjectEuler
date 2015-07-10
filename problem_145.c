// -*- compile-command: "gcc -std=c99 -o problem_145 problem_145.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

bool isReversible(unsigned long long n)
{
    unsigned long long r = 0, t = n;

    // Reverse the number
    while (t > 0)
    {
        r = r * 10 + t % 10;
        t /= 10;
    }

    // Add it to the number
    r += n;

    // Check for odd digits
    while (r > 0)
    {
        if (r % 2 == 0)
            return false;
        r /= 10;
    }

    return true;
}

int main()
{
    printf("Project Euler - Problem 145:\n"
           "A reversible number is a number that when added to its reverse only contains odd digits. How many reversible numbers are there below one-billion?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    unsigned long long limit = 1000000000;
    int count = 0;

    for (unsigned long long n=1; n<limit; n+=2)
        if (isReversible(n))
            count+=2;

    printf("Total: %d\n", count);
    printElapsedTime(start);

    return 0;
}
