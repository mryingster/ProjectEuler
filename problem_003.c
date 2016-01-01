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

    long long bigNum = 600851475143;
    int divisor = 2;

    while ( divisor < bigNum )
        if ( bigNum % divisor == 0 )
            bigNum /= divisor;
        else
            divisor++;

    printf("Largest factor found: %d\n", divisor);
    printElapsedTime(start);

    return 0;
}
