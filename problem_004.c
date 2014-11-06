// -*- compile-command: "gcc -o problem_004 problem_004.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>
#include "ceuler.h"

int main()
{
    int num1, num2;
    int product;
    int maxPalindrome = 0;

    printf("Project Euler - Problem 4:\n"
           "Find the largest palindrome made from the product of two 3-digit numbers.\n\n");

    for (num1=100 ; num1<1000 ; num1++)
    {
        for (num2=num1 ; num2<1000 ; num2++)
        {
            product = num1 * num2;
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

    return 0;
}

