// -*- compile-command: "gcc -o problem_049 problem_049.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 49:\n"
           "What 12 digit sequence do you form by concatenating three four-digit primes that are permutations of each other and increase by the same amount?\n\n");

    int basePrime = 1000, prime2, prime3;
    int found = 0;

    while (basePrime++ < 10000)
    {
        if (isPrime(basePrime) == false) continue;

        //printf("%d, %ud\n", basePrime, numSignature(basePrime)); // DEBUG
        int max = 10000 - basePrime / 2;
        int diff = 0;
        for (diff=1; diff<max; diff++)
        {
            prime2 = basePrime + diff;
            prime3 = basePrime + (2 * diff);

            if (isPrime(prime2) == false || isPrime(prime3) == false) continue;
            if (prime2 > 9999 || prime3 > 9999) continue;
            if (numSignature(basePrime) != numSignature(prime2)) continue;
            if (numSignature(basePrime) != numSignature(prime3)) continue;

            //printf("%d, %d, %d\n", basePrime, prime2, prime3);
            found++;
            break;
        }
        if (found == 2) break;
    }

    printf("12 digit number: %d%d%d\n", basePrime, prime2, prime3);
    return 0;
}
