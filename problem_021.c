// -*- compile-command: "gcc std=c99 -o problem_021 problem_021.c ceuler.c -Wall -lmxs" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"
#include <assert.h>

int main()
{
    printf("Project Euler - Problem 21:\n"
           "Evaluate the sum of all the amicable numbers under 10000.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int divisorSum = 0;
    int sum        = 0;
    short history[10001] = {0};
    bool debug = false;

    for (int number=1 ; number<10001 ; number++)
    {
        divisorSum=0;

        // Find sum of divisors
        for (int divisor=1 ; divisor<number/2+1 ; divisor++)
            if (number % divisor == 0)
                divisorSum += divisor;

        // Ignore sums larger than 10000
        if ( divisorSum > 10000 )
            continue;

        // Check if amicable
        if (history[divisorSum] == number)
        {
            if (debug == true) printf("Amicable pair %d %d\n", number, divisorSum); // DEBUG
            sum += number + divisorSum;
        }

        // Record divisor sum
        history[number] = divisorSum;
    }

    printf("Sum: %d\n", sum);
    printElapsedTime(start);

    return 0;
}
