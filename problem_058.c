// -*- compile-command: "gcc -o problem_058 problem_058.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 58:\n"
           "Start with 1 and spiral anticlockwise with numbers incrementing from 1 forming a square. What is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%%?\n\n");

    int primes = 0, corners = 0, number = 2, position = 1, length = 3;
    while(length < 30000)
    {
        // Increment numbers around spiral
        number++;
        if (position++ == (length - 1) * 4)
        {
            length += 2;
            position = 1;
        }

        // Check if corner position is prime
        if ( (position) % (length-1) == 0)
        {
            corners++;
            if (isPrime(number))
                primes++;
            //printf("%d, %d, %d - %d/%d\n", number, position, length, primes, corners); //DEBUG
        }

        // Check ratio
        if ((double)primes/(double)corners <= .1)
            break;
    }

    printf("Side Length: %d\n", length);
    return 0;
}
