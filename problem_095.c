// -*- compile-command: "gcc -std=c99 -o problem_095 problem_095.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ceuler.h"

typedef struct divisors divisors;
struct divisors{
    int sum;
    int len;
};

int divisorSum(int n, int primes[], int len)
{
    // Check if number is prime
    if (isPrime(n)) return 1;

    int sum = 1;
    int num = n;
    int index = 0;
    int factors[50000] = {};

    // Get prime factors
    while (n > 1)
    {
        if (n % primes[index] == 0)
        {
            factors[index]++;
            n /= primes[index];
            continue;
        }
        index++;
    }

    // Construct Sum using prime factors
    for (int i=0; i<len; i++)
    {
        if (factors[i] == 0) continue;
        if (factors[i] == 1) sum *= primes[i]+1;
        if (factors[i] > 1)  sum *= (pow(primes[i], factors[i]+1)-1)/(primes[i]-1);
    }

    // Don't count self as divisor
    sum -= num;

    return sum;
}

int main()
{
    printf("Project Euler - Problem 95:\n"
           "Find the smallest member of the longest amicable chain with no element exceeding one million.\n\n");

    // Generate Primes
    int primes[50000] = {};
    int index = 0;
    for (int i=2; index<50000; i++)
        if (isPrime(i))
            primes[index++] = i;
    printf("Primes generated.\n");


    // Populate our divisor chart
    static divisors divisors[1000000];
    int searchLen = sizeof(divisors)/sizeof(divisors[0]);
    for (int i = 0; i < searchLen; i++)
    {
        //printf("%d, ", i);
        divisors[i].sum = divisorSum(i, primes, index);
    }
    printf("Divisors table populated.\n");


    // Determine Chain Lengths
    for (int i = 0; i < searchLen; i++)
    {
        // Skip primes...
        if (divisors[i].sum == 1)
        {
            divisors[i].len = -1;
            continue;
        }

        // Skip Perfect Numbers
        if (divisors[i].sum == i)
        {
            divisors[i].len = -2;
            continue;
        }

        // Follow chains...
        int start = i;
        int index = divisors[i].sum;
        int length = 1;

        //printf("\n%d-->", start); // DEBUG

        while (index < searchLen)
        {
            //printf("%d-->", divisors[index].sum); // DEBUG

            // If we close a chain
            if (divisors[index].sum == start)
            {
                divisors[i].len = length;
                break;
            }

            // If we stumble into an existing loop
            if (divisors[index].len > 0)
            {
                divisors[i].len = -3;
                break;
            }

            // If we go out of bounds
            if (divisors[index].sum > searchLen)
            {
                divisors[i].len = -4;
                break;
            }

            // If we hit a chain that is going nowhere
            if (divisors[index].len < 0)
            {
                divisors[i].len = -5;
                break;
            }

            // Avoid loops that don't start on i
            if (length > 100)
            {
                divisors[i].len = -3;
                break;
            }

            index = divisors[index].sum;
            length++;
        }
    }

    int longest = 0, smallest = 0;
    for (int n=0; n<searchLen; n++)
    {
        //printf("%d: %d, %d\n", n, divisors[n].sum, divisors[n].len); // DEBUG
        if (divisors[n].len > longest)
        {
            longest = divisors[n].len;
            smallest = n;
        }
    }

    printf("Longest chain length: %d\n", longest);
    printf("Smallest chain element: %d\n", smallest);

    return 0;
}
