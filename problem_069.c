// -*- compile-command: "gcc -std=c99 -o problem_069 problem_069.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 69:\n"
           "Find the value of n <= 1,000,000 for which n/phi(n) is a maximum, where phi(n) is Euler's Totient function.\n\n");

    int Goal=1000000;
    int BigNumber=1;

    for (int i = 0 ; i < 1000 ; i++)
    {
        if (isPrime(i))
        {
            int WouldBeNumber = BigNumber * i;
            if (WouldBeNumber >= Goal)
                break;
            else
                BigNumber = WouldBeNumber;
        }
    }

    printf("Maximum: %d\n", BigNumber);
    return 0;
}
