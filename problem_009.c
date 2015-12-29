// -*- compile-command: "gcc -std=c99 -o problem_009 problem_009.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    const int target = 1000;

    printf("Project Euler - Problem 9:\n"
           "There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int product = 0;
    int a = 1;
    while (a++)
    {
        int b = a;
        while (b++)
        {
            int c = sqrt(a*a + b*b);
            int sum = a + b + c;
            if (sum > target) break;
            if (c != sqrt(a*a + b*b)) continue;
            if (sum == target)
            {
                product = a * b * c;
                break;
            }
        }
        if (product != 0) break;
    }

    printf("Product: %d\n", product);
    printElapsedTime(start);

    return 0;
}
