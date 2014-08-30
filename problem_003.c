// -*- compile-command: "gcc -o problem_003 problem_003.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    int i;
    unsigned long long bigNum;
    int lastFactor;

    bigNum=600851475143;
    lastFactor=0;

    printf("Project Euler - Problem 3:\n"
           "What is the largest prime factor of the number 600851475143 ?\n\n");

    for (i=2; i<10000; i++)
    {
        if ( bigNum % i )
            printf("");
        else
	{
            //printf("Factor Found: %i\n", i);
            bigNum=bigNum/i;
            lastFactor=i;
            i=2;
	}
    }
    printf("Largest factor found: \033[1m%i\033[0m\n", lastFactor);

    return 0;
}
