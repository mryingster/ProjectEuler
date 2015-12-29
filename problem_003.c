// -*- compile-command: "gcc -std=c99 -o problem_003 problem_003.c  ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 3:\n"
           "What is the largest prime factor of the number 600851475143?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    unsigned long long bigNum = 600851475143;
    int lastFactor = 0;

    for ( int i=2; i<10000; i++ )
        if ( bigNum % i == 0 )
	{
            //printf("Factor Found: %i\n", i);
            bigNum /= i;
            lastFactor = i;
            i = 2;
	}

    printf("Largest factor found: %d\n", lastFactor);
    printElapsedTime(start);

    return 0;
}
