// -*- compile-command: "gcc -std=c99 -o problem_127 problem_127.c ceuler.c -Wall -lm -O3" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

unsigned long long rad(int a, int *primes, int nprimes)
{
    unsigned long long t = a;
    unsigned long long r = 1;
    int n = 0;
    bool counted = false;

    while (t > 1 && n < nprimes)
    {
        if (t % primes[n] == 0)
        {
            t /= primes[n];
            if (counted == false)
            {
                r *= primes[n];
                counted = true;
            }
        }
        else
        {
            n++;
            counted = false;
        }
    }

    return r;
}

int main()
{
    printf("Project Euler - Problem 127:\n"
           "Find the sum of abc-hits for c < 120000.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int limit = 120000;
    int count = 0;
    unsigned long long sum = 0;
    bool debug = false;

    // Precompute Primes
    int nprimes = limit;
    int *primes = malloc(nprimes*sizeof(int));
    primeSieve(primes, nprimes);
    if (debug == true)
    {
        printf("Primes computed\n");
        printElapsedTime(start);
    }

    // Precompute Radicals
    unsigned long long *radical = malloc(limit*sizeof(unsigned long long));
    for (int n=1; n<limit; n++)
        radical[n] = rad(n, primes, nprimes);
    if (debug == true)
    {
        printf("Radicals computed\n");
        printElapsedTime(start);
    }

    // Find ABC-Hits
    for (int a=1 ; a<limit; a++)
    {
        for (int b=a+1 ; b<limit-a; b++)
        {
            int c = a + b;
            unsigned long long r = radical[a] * radical[b] * radical[c];
            if (r >= a + b) continue;
            if (gcd(a, b) != 1) continue;

            // Passed the tests
            count++;
            sum += c;

            if (debug == true)
                printf("rad(%d * %d * %d) = %llu\n", a, b, c, r);
        }
    }

    printf("Sum: %llu (Total: %d)\n", sum, count);
    printElapsedTime(start);

    free(radical);
    free(primes);
    return 0;
}
