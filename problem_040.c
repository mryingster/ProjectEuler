// -*- compile-command: "gcc -o problem_040 problem_040.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"
#include <stdbool.h>

int main()
{
    printf("Project Euler - Problem 40:\n"
           "If dn represents the nth digit of the fractional part, find the value of the following expression.\n"
           "d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000 \n\n");

    unsigned long number = 1;
    unsigned long count  = 0;
    int total = 1;

    while (count < 1000000)
    {
        unsigned long tmpNum   = number;
        unsigned long tmpCount = numberOfDigits(number);
        while (tmpCount > 0)
        {
            if ( powerOf(count+tmpCount, 10) == true)
                total *= tmpNum % 10;
            tmpNum /= 10;
            tmpCount--;
        }
        count += numberOfDigits(number);
        number++;
    }

    printf("Total: %d\n", total);

    return 0;
}
