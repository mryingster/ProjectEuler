// -*- compile-command: "gcc -o problem_040 problem_040.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 40:\n"
           "If dn represents the nth digit of the fractional part, find the value of the following expression.\n"
           "d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000 \n\n");

    unsigned long number = 1;
    unsigned long count  = 0;
    int fraction[1000100]={};

    // Fill up array with sequential integers
    while (count < 1000000)
    {
        unsigned long tmpNum   = number;
        unsigned long tmpCount = numberOfDigits(number);
        // Add digit to array in reverse order
        while (tmpCount > 0)
        {
            fraction[count+tmpCount] = tmpNum % 10;
            tmpNum /= 10;
            tmpCount--;
        }
        count += numberOfDigits(number);
        number++;
    }

    // Perform the multiplication
    number = fraction[1] *    fraction[10] *    fraction[100] *
             fraction[1000] * fraction[10000] * fraction[100000] *
             fraction[1000000];

    printf("Total: %lu\n", number);

    return 0;
}
