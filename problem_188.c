// -*- compile-command: "gcc -std=c99 -o problem_188 problem_188.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ceuler.h"

unsigned long long exponent(int base, unsigned long long exp) {
    unsigned long long n = base;
    for (int i=1; i<exp; i++) {
        n *= base;
        n %= 100000000;
    }

    return n;
}

unsigned long long tetration(int base, int exp){
    unsigned long long result = 1;
    unsigned long long last_result = 0;

    for (int i=0; i<exp; i++){
        result = exponent(base, result);

        // If result doesn't change, we have our answer!
        if (result == last_result)
            break;
        last_result = result;
    }

    return result;
}

int main()
{
    printf("Project Euler - Problem 188:\n"
           "Find the last 8 digits of the tetration of 1777^^1855\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    printf("%llu\n", tetration(1777, 1855));

    //printf("Nth: %d\n", prime[2000-1]); // Find 2000th element
    printElapsedTime(start);

    return 0;
}
