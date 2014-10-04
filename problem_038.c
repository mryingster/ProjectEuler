// -*- compile-command: "gcc -o problem_038 problem_038.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 38:\n"
           "What is the largest 1 to 9 pandigital that can be formed by multiplying a fixed number by 1, 2, 3, ... ?\n\n");

    long pandigital = 0;
    long candidate  = 0;
    int  seed       = 1;
    int  newNum;
    int  multiplicand;

    while ( seed < 9999 )
    {
        multiplicand = 1;
        candidate = seed;
        while ( numberOfDigits(candidate) < 9 )
        {
            multiplicand++;
            newNum = (seed * multiplicand);
            candidate *= pow(10, numberOfDigits(newNum));
            candidate += newNum;
            if ( numberOfDigits(candidate) == 9 )
                if ( isPandigital(candidate) == true )
                    if ( candidate > pandigital )
                        pandigital = candidate;
        }
        seed++;
    }

    printf("Largest pandigital: %ld\n", pandigital);
    //932718654
    return 0;
}
