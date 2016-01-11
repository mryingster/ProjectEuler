// -*- compile-command: "gcc -std=c99 -o problem_016 problem_016.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 16:\n"
           "What is the sum of the digits of the number 2^1000\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int bignum[350] = {0};
    int total = 0;
    bool debug = false;

    bignum[1] = 2;

    for (int i=1 ; i<1000 ; i++)
    {
        //Multiply each element
        for (int n=0 ; n<350 ; n++)
            bignum[n]=bignum[n]*2;

        //Spill each element if needed
        for (int n=0 ; n<350 ; n++)
        {
            while (bignum[n] > 9)
            {
                bignum[n+1]=bignum[n+1]+1;
                bignum[n]=bignum[n]-10;
            }
        }

        // DEBUG: Print each element
        if (debug == true)
        {
            for (int n=350 ; n>1 ; n--)
                printf("%i",bignum[n]);
            printf("\n\n");
        }
    }

    // Add digits together
    for (int n=0 ; n<350 ; n++)
        total += bignum[n];

    printf("Total: %i\n", total);
    printElapsedTime(start);

    return 0;
}
