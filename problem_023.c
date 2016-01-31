// -*- compile-command: "gcc -std=c99 -o problem_023 problem_023.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

bool isAbundant(int n)
{
    int sum = 1, limit = n/2+1;
    for (int i=2; i<limit; i++)
    {
        if (n % i == 0)
            sum += i;
        if (sum > n)
            return true;
    }
    return false;
}

int main()
{
    printf("Project Euler - Problem 23:\n"
           "Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    const int limit = 28123;
    int abundant[28123] = {0};
    int abundantCount = 0;

    // Find abundant numbers and store in array, adundant
    for (int n=1 ; n <= 28123 ; n++)
        if (isAbundant(n) == true)
            abundant[abundantCount++] = n;

    bool abundantSums[28123] = {false};
    for (int a=0; a<abundantCount; a++)
        for (int b=a; b<abundantCount; b++)
        {
            int abundantSum = abundant[a]+abundant[b];
            if (abundantSum > limit) break;
            abundantSums[abundantSum] = true;
        }

    int sum = 0;
    for (int i=0; i<limit; i++)
        if (abundantSums[i] == false)
            sum += i;

    printf("Sum: %d\n", sum);
    printElapsedTime(start);

    return 0;
}
