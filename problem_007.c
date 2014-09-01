// -*- compile-command: "gcc -o problem_007 problem_007.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

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
    int primeCount=0, candidate=0;
    int primes[10002] = {0};

    printf("Project Euler - Problem 7:\n"
           "What is the 10,001st prime number?\n\n");

    for (candidate=2 ; candidate<10000000 ; candidate++)
    {
        if ( isPrime(candidate, primes) )
        {
            primes[primeCount] = candidate;
            primeCount++;
        }
        if (primeCount == 10001)
            break;
    }

    printf("10,001st prime: \033[1m%i\033[0m\n", candidate);
    //Answer: 104743

    return 0;
}
