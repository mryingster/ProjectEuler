// -*- compile-command: "gcc -o problem_012 problem_012.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int isPrime(int input, int *primes)
{
    int n=0;
    if (input == 2)
        return 1;
    else
        while (primes[n] != 0)
        {
            if (input % primes[n] == 0)
                return 0;
            n++;
        }
    return 1;
}

int findDivisors(int input, int *primes, int primesToFind)
{
    int i, count=1;
    int primeCount[primesToFind];
    for (i=0; i<primesToFind; i++)
        primeCount[i] = 0;

    // Prime factorization
    while (input != 1)
    {
        for (i=0; i<primesToFind; i++)
        {
            if (input % primes[i] == 0)
            {
                input = input / primes[i];
                primeCount[i]++;
                //count++;
            }
        }
    }

    // Convert prime factorization to divisors
    for (i=0; i<primesToFind; i++)
    {
        if (primeCount[i] > 0)
        {
            count=count*(primeCount[i]+1);
        }
    }

    return count;
}

int main()
{
    int i=0, triangle=0, divisors=0;
    int primeCount = 0;

    int primesToFind = 1500;
    int primes[primesToFind];

    printf("Project Euler - Problem 12:\n"
           "What is the value of the first triangle number to have over five hundred divisors?\n\n");

    // Initialize primesToFind
    for (i=0; i<primesToFind; i++)
        primes[i] = 0;

    // Pre-Calculate Primes
    //printf("Calculating primes...\n");
    i=1;
    while (primeCount < primesToFind)
    {
        i++;
        if (isPrime(i, primes))
        {
            primes[primeCount]=i;
            //printf("%i, %i\n", i, primeCount);
            primeCount++;
        }
    }
    //printf("Primes Calculated.\n");

    // Calculate Triangles
    i=0;
    while(i<1000000)
    {
        i++;
        triangle = triangle+i;
        divisors = findDivisors(triangle, primes, primesToFind);
        if (divisors > 500)
            break;
        i++;
        triangle = triangle+i;
    }

    printf("Triangle Value: \033[1m%i\033[0m, Divisors: %i\n", triangle, divisors);
    return 0;
}
