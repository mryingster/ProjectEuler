// -*- compile-command: "gcc -o problem_004 problem_004.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    int i, j, m, n, palindrome, bigpalindrome;
    char product[10];

    printf("Project Euler - Problem 4:\n"
           "Find the largest palindrome made from the product of two 3-digit numbers.\n\n");

    for (i=100 ; i<1000 ; i++)
    {
        for (j=i ; j<1000 ; j++)
        {
            snprintf(product, sizeof(product), "%i", j*i);
            //printf("%s\n", product);
            palindrome = 1;

            for (m=0 ; product[m]!='\0'; m++);
            for (n=0 ; n<m ; n++)
                if (product[n] != product[m-1-n])
                    palindrome = 0;
            if (palindrome == 1)
            {
                if (i*j>bigpalindrome)
                    bigpalindrome=i*j;
            }
        }
    }

    printf("Largest palindrome: \033[1m%i\033[0m\n", bigpalindrome);

    return 0;
}

