// -*- compile-command: "gcc -o problem_012 problem_012.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <ceuler.h>

int findDivisors(int input, int *primes, int primesToFind)
{
    int index, count=1;
    int primeCount[primesToFind];
    for (index=0; index<primesToFind; index++)
        primeCount[index] = 0;

    // Prime factorization
    while (input != 1)
        for (index=0; index<primesToFind; index++)
            if (input % primes[index] == 0)
            {
                input = input / primes[index];
                primeCount[index]++;
            }

    // Convert prime factorization to divisors
    for (index=0; index<primesToFind; index++)
        if (primeCount[index] > 0)
            count *= (primeCount[index]+1);

    return count;
}

int main()
{
    int index=0, triangle=0, divisors=0;
    int primeCount = 0;

    int primesToFind = 1500;
    int primes[primesToFind];

    printf("Project Euler - Problem 12:\n"
           "What is the value of the first triangle number to have over five hundred divisors?\n\n");

    // Initialize primesToFind
    for (index=0; index<primesToFind; index++)
        primes[index] = 0;

    // Pre-Calculate Primes
    index = 1;
    while (primeCount < primesToFind)
    {
        index++;
        if (isPrimeOpt(index, primes))
        {
            primes[primeCount]=index;
            primeCount++;
        }
    }

    // Calculate Triangles
    index = 0;
    while(index<1000000)
    {
        index++;
        triangle += index;

        // Skip numbers not divisible by 3 or 5
        if ( (triangle % 3 != 0) || (triangle % 5 != 0) )
            continue;
        divisors = findDivisors(triangle, primes, primesToFind);

        if (divisors > 500)
            break;
    }

    printf("Triangle Value: %d, Divisors: %d\n", triangle, divisors);
    return 0;
}
