// -*- compile-command: "gcc -o problem_010 problem_010.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>

int isPrime(int input, int *primes)
{
    int n=0;

    if (input == 2)
        return 1;
    else
        while (primes[n] != 0)
        {
            if (input % primes[n] == 0)
                return 0;
            n++;
        }
    return 1;
}

int main()
{
    int i = 0, n = 0;
    int primes[500000] = {0};
    unsigned long long sum;

    printf("Project Euler - Problem 10:\n"
           "Find the sum of all the primes below two million.\n\n");

    for (i=2 ; i<2000000 ; i++)
    {
        if (isPrime(i, primes))
	{
            sum=sum+i;
            primes[n]=i;
            n++;
            //printf("prime:%i Total:%llu\n", i, sum);
	}
    }
    printf("Sum of primes: \033[1m%llu\033[0m\n", sum);
    return 0;
}
