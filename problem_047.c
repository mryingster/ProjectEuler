// -*- compile-command: "gcc -o problem_047 problem_047.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

int primeFactors(int number, const int * primes, const int primeIndex)
{
    int count = 0;
    int factors = 1;
    int pIndex = 0;

    while (number > 1)
    {
        if (count == 1) factors++;
        if (number % primes[pIndex] == 0)
        {
            number /= primes[pIndex];
            count++;
        }
        else
        {
            pIndex++;
            count = 0;
        }
    }
    return factors;
}

int main()
{
    printf("Project Euler - Problem 47:\n"
           "What is the of four consecutive integers to have four distinct prime factors?\n\n");

    int primes[50000] = {};
    int primeIndex = 0;
    int composite = 1;
    int count = 0, candidate = 0;

    while ( composite++ && count != 4 )
    {
        if (isPrimeOpt(composite, primes) == true)
        {
            primes[primeIndex++] = composite;
            count = 0;
        }
        else // is composite number
        {
            if (primeFactors(composite, primes, primeIndex) == 4)
            {
                if (count == 0)
                    candidate = composite;
                count++;
            }
            else
            {
                count = 0;
            }
        }
    }

    printf("First digit: %d\n", candidate);

    return 0;
}
