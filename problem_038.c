// -*- compile-command: "gcc -o problem_038 problem_038.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 38:\n"
           "What is the largest 1 to 9 pandigital that can be formed by multiplying a fixed number by 1, 2, 3, ... ?\n\n");

    long pandigital = 0;

    for ( int seed=1; seed<9999; seed++ )
    {
        long candidate = seed;
        int multiplicand = 1;
        int numDigits = numberOfDigits(candidate);
        while ( numDigits < 9 )
        {
            multiplicand++;
            int newNum = seed * multiplicand;
            candidate *= pow(10, numberOfDigits(newNum));
            candidate += newNum;
            numDigits = numberOfDigits(candidate);

            if ( numDigits == 9 )
                if ( isPandigital(candidate) == true )
                    if ( candidate > pandigital )
                        pandigital = candidate;
        }
    }

    printf("Largest pandigital: %ld\n", pandigital);

    return 0;
}
