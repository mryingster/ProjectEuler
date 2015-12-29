// -*- compile-command: "gcc -std=c99 -o problem_005 problem_005.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 5:\n"
           "What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int number = 1000;

    while ( number += 20 )
    {
        bool candidate = true;
        for ( int divisor=2 ; divisor<=20 ; divisor++ )
        {
            if ( number % divisor != 0 )
            {
                candidate = false;
                break;
            }
        }
        if ( candidate == true )
            break;
    }

    printf("Smallest number: %d\n", number);
    printElapsedTime(start);

    return 0;
}

