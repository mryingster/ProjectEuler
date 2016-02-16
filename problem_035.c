// -*- compile-command: "gcc -std=c99 -o problem_035 problem_035.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int rotateDigit(int input)
{
    int output = input / 10;
    int lastDigit = input % 10;
    int digits = 0;

    while ( (input/=10) > 0 )
        digits++;

    output += pow(10, digits) * lastDigit;

    return output;
}

int main()
{
    printf("Project Euler - Problem 35:\n"
           "How many circular primes are there below one million?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    const int limit = 1000000;
    int count = 0;

    for ( int n=2; n<limit; n++ )
    {
        if (isPrime(n) == false) continue;
        int t = rotateDigit(n);
        bool isCircular = true;
        while (t != n)
        {
            if (isPrime(t) != true)
            {
                isCircular = false;
                break;
            }
            t = rotateDigit(t);
        }

        if (isCircular == true)
            count++;
    }

    printf("%d\n", count);
    printElapsedTime(start);

    return 0;
}
