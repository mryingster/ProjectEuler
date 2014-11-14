// -*- compile-command: "gcc -std=c99 -o problem_063 problem_063.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Project Euler - Problem 63:\n"
    "How many n-digit positive integers exist which are also an nth power?\n\n");

    int count = 0;
    for (int i = 1 ; i < 100 ; i++)
        for (int n = 1 ; n < 100 ; n++)
        {
            double result = pow(i, n);
            int digits = floor(log10(result))+1;
            if (digits == n)
            {
                //printf("%d^%d = %F (%d)\n", i, n, result, digits); //DEBUG
                count++;
            }
            else if (digits > n)
                break;
        }

    printf("Total n-digit integers: %d\n", count);
    return 0;
}
