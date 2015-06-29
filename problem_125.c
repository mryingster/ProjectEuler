// -*- compile-command: "gcc -std=c99 -o problem_125 problem_125.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 125:\n"
           "Find the sum of all numbers less than 10^8 that are both palindromic and can be written as the sum of consecutive squares.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    unsigned long long sum = 0;
    unsigned long long limit = pow(10, 8);
    int squarelim = sqrt(limit)+1;
    bool *history = malloc(limit*sizeof(bool));
    bool debug = false;

    // Find sums
    for (int start=1; start<squarelim; start++)
    {
        unsigned long long n = start * start;
        for (int end=start+1; end<squarelim; end++)
        {
            n += end * end;
            if (n >= limit) break;
            if (isPalindromic(n))
            {
                if (history[n] == false)
                {
                    history[n] = true;
                    sum += n;
                    if (debug == true)
                        printf("%llu\n", n);
                }
            }
        }
    }

    printf("Sum: %llu\n", sum);
    printElapsedTime(start);

    free(history);
    return 0;
}
