// -*- compile-command: "gcc -std=c99 -o problem_077 problem_077.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

void debugPrint(int a[], int l)
{
    for (int i=0; i<l-1; i++)
        printf("%d, ", a[i]);
    printf("%d\n", a[l-1]);
}

int main()
{
    printf("Project Euler - Problem 77:\n"
           "What is the first value that can be written as the sum of prime numbers in over 5,000 different ways?\n\n");

    int primes[100] = {};
    int primeIndex = 0;
    int limit = 5000;
    int number = 10;

    // Populate primes
    for (int i=2; primeIndex<100; i++)
        if (isPrime(i))
            primes[primeIndex++] = i;

    while (true)
    {
        int ways[number+1];
        for (int i=1; i <= number; i++) ways[i] = 0;
        ways[0] = 1;

        for (primeIndex = 0; primeIndex < sizeof(primes)/sizeof(primes[0]); primeIndex++)
            for (int i = primes[primeIndex]; i < number+1; i++)
                ways[i] += ways[i-primes[primeIndex]];

        //debugPrint(ways, number+1);

        if (ways[number] > limit) break;

        number++;
    }

    printf("First digit: %d\n", number);
    return 0;
}
