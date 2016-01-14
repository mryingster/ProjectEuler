// -*- compile-command: "gcc -std=c99 -o problem_020 problem_020.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 20:\n"
           "Find the sum of the digits in the number 100!\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int bigNum[1000] = {0};
    bool debug = false;

    bigNum[997]=1; // Starting value is 100

    for (int factorial=99 ; factorial>0 ; factorial--)
    {
        // Multiply by factorial
        for (int i=999 ; i>=0 ; i--)
            bigNum[i] *= factorial;

        // Carry-over each element if needed
        for (int i=999 ; i>=0 ; i--)
            while (bigNum[i] > 9)
            {
                bigNum[i]   -= 10;
                bigNum[i-1] += 1;
            }

        // DEBUG - Print result
        if (debug == true)
        {
            int i = 0;
            while (bigNum[++i] == 0);
            for (; i<1000 ; i++)
                printf("%d", bigNum[i]);
            printf("\n");
        }
    }

    int sum = 0;
    for (int i=0 ; i<1000 ; i++)
        sum += bigNum[i];

    printf("%d\n", sum);
    printElapsedTime(start);

    return 0;
}
