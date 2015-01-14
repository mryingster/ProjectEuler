// -*- compile-command: "gcc -std=c99 -o problem_073 problem_073.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>
#include "ceuler.h"

bool reduced(int n, int d, int primes[], int p)
{
    for(int i=0 ; i < p; i++)
    {
        if (d % primes[i] == 0 && n % primes[i] == 0)
            return false;
        if (primes[i] > n)
            return true;
    }
    return true;
}

int main(){
    printf("Project Euler - Problem 73:\n"
           "How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d <= 12,000?\n\n");

    // Generate prime list
    int primes[1000];
    int i=0, n=1;
    while (i < 1000)
        if (isPrime(++n))
            primes[i++] = n;

    // Brute force through all fractions
    int max=12000+1;
    int count=0;
    for (int d=5; d<max; d++)
        for (int n=d/3+1; n<d/2+1; n++)
            if (reduced(n, d, primes, i) == true) // Check if it's reducible
                count++;

    printf("Total fractions: %d\n", count);
    return 0;
}
