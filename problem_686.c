// -*- compile-command: "gcc -std=c99 -o problem_686 problem_686.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 686:\n"
           "Find the 678910th power of 2 to start with the digits 123.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int search  = 123;
    int count   = 678910;
    long unsigned power  = 1;
    long long unsigned n = 2;

    while (count > 0){
        n *= 2;
        power += 1;

        // Look for leading digits
        long long unsigned t = n;
        while (t > search)
            t /= 10;
        if (t == search)
            count -= 1;

        // Keep our number smallish
        while (n > 100000000000000000)
            n /= 10;
    }

    printf("Power: %lu\n", power);
    printElapsedTime(start);

    return 0;
}

