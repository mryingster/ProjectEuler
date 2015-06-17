// -*- compile-command: "gcc -std=c99 -o problem_348 problem_348.c ceuler.c -Wall -lm -O3" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 348:\n"
           "Find the sum of the 5 smallest pamindromic numbers that be expressed exactly 4 ways as the sum of a square and a cube.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int lim = 50000;
    int limit = 1000000000;
    short *palindromes = malloc(limit*sizeof(short));

    bool debug = false;

    // Count all the factors for all numbers under limit
    for (int i=2; i<lim; i++)
    {
        for (int n=0; n<i; n++)
        {
            unsigned long long number = pow(i, 2) + pow(n, 3);
            if (number > limit) break;

            if (isPalindromic(number))
            {
                if (debug == true)
                    printf("%d^2 + %d^3 = %llu\n", i, n, number);
                palindromes[number]++;
            }
        }
    }

    int sum = 0, count = 0;
    for (int i=2; i<limit; i++)
        if (palindromes[i] == 4)
        {
            if (debug == true)
                printf("%d: %d\n", i, palindromes[i]);
            sum += i;
            if (count == 5) break;
        }

    printf("Sum: %d\n", sum);
    printElapsedTime(start);

    free(palindromes);
    return 0;
}
