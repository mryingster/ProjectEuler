// -*- compile-command: "gcc -o problem_003 problem_003.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    unsigned long long bigNum = 600851475143;
    int lastFactor = 0;
    int i;

    printf("Project Euler - Problem 3:\n"
           "What is the largest prime factor of the number 600851475143 ?\n\n");

    for ( i=2; i<10000; i++ )
        if ( bigNum % i == 0 )
	{
            //printf("Factor Found: %i\n", i);
            bigNum /= i;
            lastFactor = i;
            i = 2;
	}

    printf("Largest factor found: %d\n", lastFactor);

    return 0;
}
