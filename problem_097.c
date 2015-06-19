// -*- compile-command: "gcc -std=c99 -o problem_097 problem_097.c -Wall ceuler.c -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 97\n");
    printf("Find the last ten digits of the prime number, 28433×(2^7830457)+1.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    unsigned long long n = 2;
    unsigned long long max = 10000000000;  // 10 digits
    int exponent = 7830457;                // 2's exponent
    int base = 28433;                      // Starting value

    while (exponent > 1)
    {
        n *= 2;
        exponent--;
        while (n > max) n -= max;
    }

    n *= base;
    n++;

    while (n > max) n -= max;

    printf("%llu\n", n);
    printElapsedTime(start);

    return 0;
}
