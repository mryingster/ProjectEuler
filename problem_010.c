// -*- compile-command: "gcc -o problem_010 problem_010.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>

int main()
{
    int i, n, prime;
    unsigned long long sum;
    i=n=sum=0;

    printf("Project Euler - Problem 10:\n"
           "Find the sum of all the primes below two million.\n\n");

    for (i=1 ; i<2000000 ; i++)
    {
        prime=1;
        for (n=2 ; n<i ; n++)
        {
            if (i % n)
                prime=1;
            else
            {
                if (i == 2)
                    prime=1;
                else
                    prime=0;
                break;
            }
        }
        if (prime == 1)
	{
            sum=sum+i;
	}
    }
    printf("Sum of primes: \033[1m%llu\033[0m\n", sum);
    return 0;
}
