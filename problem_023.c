// -*- compile-command: "gcc -std=c99 -o problem_023 problem_023.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main() {
    printf("Project Euler - Problem 23:\n"
           "Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    const int limit = 28123;

    // Find abundant numbers and store in array, abundant
    int sums[28123] = {0};
    int abundant[28123] = {0};
    int abundantCount = 0;
    for (int n=1; n<limit; n++)
    {
        for (int m=2; m*n<limit; m++)
            sums[m*n] += n;
        if (sums[n] > n)
            abundant[abundantCount++] = n;
    }

    // Find all abundant sums and track in boolean array
    bool abundantSums[28123] = {false};
    for (int a=0; a<abundantCount; a++)
        for (int b=a; b<abundantCount; b++)
        {
            int abundantSum = abundant[a]+abundant[b];
            if (abundantSum > limit) break;
            abundantSums[abundantSum] = true;
        }

    // Add up non-abundant sums
    int sum = 0;
    for (int i=0; i<limit; i++)
        if (abundantSums[i] == false)
            sum += i;

    printf("Sum: %d\n", sum);
    printElapsedTime(start);

    return 0;
}
