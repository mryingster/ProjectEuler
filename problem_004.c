// -*- compile-command: "gcc -std=c99 -o problem_004 problem_004.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 4:\n"
           "Find the largest palindrome made from the product of two 3-digit numbers.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int maxPalindrome = 0;
    for (int num1=100 ; num1<1000 ; num1++)
    {
        for (int num2=num1 ; num2<1000 ; num2++)
        {
            int product = num1 * num2;
            if (isPalindromic(product) == true)
            {
                if ( product > maxPalindrome)
                {
                    maxPalindrome = product;
                }
            }
        }
    }

    printf("Largest palindromic product: %d\n", maxPalindrome);
    printElapsedTime(start);

    return 0;
}

