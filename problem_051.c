// -*- compile-command: "gcc -o problem_051 problem_051.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int arrayToInt(int * array, const int length)
{
    int output = 0, index;
    for (index=0 ; index<length ; index++)
        output += array[index] * pow(10, length-1-index);

    return output;
}

void intToArray(int * array, const int length, int input)
{
    int index;
    for (index = length-1; index>=0; index--)
    {
        array[index] = input % 10;
        input /= 10;
    }
}

bool satisfiesRequirements(int input)
{
    int prime[6];
    int length = sizeof(prime) / sizeof(prime[0]);

    // Convert integer to array
    intToArray(prime, length, input);

    // Look for 3 matching numbers
    int  pos1, pos2, pos3, sub;
    for (pos1=0 ; pos1<4 ; pos1++)
        for (pos2=pos1+1 ; pos2<5 ; pos2++)
            for (pos3=pos2+1 ; pos3<6 ; pos3++)
            {
                int count=0;
                if (prime[pos1] == prime[pos2] && prime[pos1] == prime[pos3] && prime[pos1] != 0)
                {
                    // Substitute matching digits with 1-10 and count how many are prime
                    for (sub=1 ; sub<10 ; sub++)
                    {
                        prime[pos1] = prime[pos2] = prime[pos3] = sub;

                        // Convert to int, check if prime. Increment if prime.
                        if (isPrime(arrayToInt(prime, length)))
                            count++;
                    }

                    // If we find a family of 8, return
                    if (count == 8) return true;
                }
            }
    return false;
}

int main()
{
    printf("Project Euler - Problem 51:\n"
           "Find the smallest prime which, by replacing part of the number with the same digit, is part of an eight prime value family.\n\n");

    int prime = 1;

    while ( prime += 2 < 1000000 )
    {
        if (isPrime(prime) == false) continue;

        // Check if this prime satisfies question requirements
        if (satisfiesRequirements(prime) == true)
            break;
    }
    printf("Smallest prime: %d\n", prime);
    return 0;
}
