// -*- compile-command: "gcc -o problem_016 problem_016.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    printf("Project Euler - Problem 16:\n"
           "What is the sum of the digits of the number 2^1000\n\n");

    int bignum[350] = {0};
    int n = 0, i = 0, total = 0;

    bignum[1]=2;

    for (i=1 ; i<1000 ; i++)
    {
        //Multiply each element
        for (n=0 ; n<350 ; n++)
            bignum[n]=bignum[n]*2;

        //Spill each element if needed
        for (n=0 ; n<350 ; n++)
        {
            while (bignum[n] > 9)
            {
                bignum[n+1]=bignum[n+1]+1;
                bignum[n]=bignum[n]-10;
            }
        }

        /*
        // DEBUG: Print each element
        for (n=350 ; n>1 ; n--)
            printf("%i",bignum[n]);
        printf("\n\n");
        */
    }

    // Add digits together
    for (n=0 ; n<350 ; n++)
        total=total+bignum[n];

    printf("Total: %i\n", total);

    return 0;
}
