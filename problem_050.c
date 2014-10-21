// -*- compile-command: "gcc -o problem_050 problem_050.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    int base         = 1;
    int number       = 1;
    int chainCount   = 0;
    int biggestChain = 0;
    int biggestPrime = 0;
    int sum          = 0;

    printf("Project Euler - Problem 50:\n"
    "Which prime, below one-million, can be written as the sum of the most consecutive primes?\n\n");

    // Pick a base prime number
    while (++base < 100)
    {
        if (isPrime(base))
        {
            number = base;
            chainCount = 0;
            sum = 0;

            // Add consecutive prime to sum while sum is less than limit
            while (sum < 1000000)
            {
                if (isPrime(number))
                {
                    chainCount++;
                    sum += number;
                    if (isPrime(sum))
                    {

                        // If number of primes used is longer, record it
                        if (chainCount > biggestChain)
                        {
                            //printf("Base: %d, Length: %d, Sum: %d\n", base, chainCount, sum); // DEBUG
                            biggestChain = chainCount;
                            biggestPrime = sum;
                        }
                    }
                }
                number++;
            }
        }
    }

    printf("Answer: %d\n", biggestPrime);
    return 0;
}
