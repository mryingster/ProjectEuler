// -*- compile-command: "gcc -std=c99 -o problem_070 problem_070.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "ceuler.h"

int totient(int n, int primes[], int c, float min)
{
    int result = n;
    int threshold = n / min;
    int i = 0;

    while(n > 1 && i < c)
    {
        if (n % primes[i] == 0)
        {
            while (n % primes[i] == 0) n /= primes[i];
            result *= (1 - (1.0/(float)primes[i]));
            if (result <= threshold) return 1;
        }
        i++;
    }

    return result;
}

typedef struct answer answer;
struct answer
{
    int number;
    int phi;
    float ratio;
};

int main()
{
    printf("Project Euler - Problem 70:\n"
           "Find the value of n, 1 < n < 10^7, for which phi(n) is a permutation of n and the ratio n/phi(n) produces a minimum.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    answer min = {0, 0, 2};
    const int max = 10000000;
    const int search_max = sqrt(max);
    bool debug = false;

    // Populate primes
    int primes[5000] = {0};
    int nprimes = sizeof(primes)/sizeof(primes[0]);
    primeSieve(primes, nprimes);

    for( int a = 100; primes[a] < search_max; a++)
    {
        int n = primes[a];
        for( int b = a; n < max; b++)
        {
            n = primes[a] * primes[b];

            int phi = totient(n, primes, nprimes, min.ratio);
            if ((float)n/(float)phi < min.ratio)
                if (numSignature(n) == numSignature(phi))
                {
                    min.ratio = (float)n/(float)phi;
                    min.number = n;
                    min.phi = phi;
                    if (debug == true)
                        printf("(%d x %d) %d : %d (%F)\n",
                               primes[a], primes[b],
                               min.number, min.phi, min.ratio);
                }
        }
    }

    printf("Minimum: %d (Ratio: %F)\n", min.number, min.ratio);
    printElapsedTime(start);

    return 0;
}
