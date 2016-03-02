// -*- compile-command: "gcc -std=c99 -o problem_039 problem_039.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 39:\n"
           "Find the perimeter of a right triangle (p) that has the most possible solutions, where the perimiter is less than or equal to 1000.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int perimeter[1000] = {};
    int limit = sizeof(perimeter)/sizeof(perimeter[0]);
    int largest = 0;

    for (int a=0; a<limit; a++)
        for (int b=a; b<limit; b++)
        {
            // Check if side c is integer length
            int rightSide = (a*a) + (b*b);
            int c = sqrt(rightSide);
            if ( c*c != rightSide) continue;

            // Make sure perimeter is less than limit
            int p = a + b + c;
            if ( p >= limit ) continue;

            // Keep track of perimeter with most solutions
            if ( ++perimeter[p] > perimeter[largest] )
                largest = p;
        }

    printf("%d\n", largest);
    printElapsedTime(start);

    return 0;
}
