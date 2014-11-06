// -*- compile-command: "gcc -o problem_010 problem_010.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    int index  = 0;
    int number = 0;
    int primes[500000] = {0};
    unsigned long long sum = 0;

    printf("Project Euler - Problem 10:\n"
           "Find the sum of all the primes below two million.\n\n");

    for (number=2 ; number<2000000 ; number++)
        if (isPrimeOpt(number, primes))
	{
            sum += number;
            primes[index] = number;
            index++;
            //printf("prime:%i Total:%llu\n", i, sum); //DEBUG
	}

    printf("Sum of primes: %llu\n", sum);

    return 0;
}
