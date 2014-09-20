// -*- compile-command: "gcc -o problem_035 problem_035.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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

int rotateDigit(int input)
{
    int output = input / 10;
    int lastDigit = input % 10;
    int digits = 0;

    while ( (input/=10) > 0 )
        digits++;

    output += pow(10, digits) * lastDigit;

    return output;
}

int inArray(int input, int *array)
{
    int index;
    for (index=0 ; index<500000 ; index++)
        if (input == array[index])
            return index;
    return 0;
}

bool containsEvenNum(int input)
{
    while (input > 0)
    {
        int digit = input % 10;
        if ( digit % 2 == 0)
            return true;
        input /= 10;
    }
    return false;
}

int main()
{
    const int maxPrime = 1000000;
    int count = 0;
    int primes[500000] = {};
    int primeCount = 0;
    int index = 0;

    printf("Project Euler - Problem 35:\n"
           "How many circular primes are there below one million?\n\n");

    printf("Calculating primes to %d.\n", maxPrime);
    //Precalculate primes to maxPrime
    for ( index=2 ; index<maxPrime ; index++ )
    {
        if ( isPrime(index, primes) )
        {
            primes[primeCount] = index;
            primeCount++;
        }
    }

    printf("Searching for circular numbers...\n\n");
    // Go through primes and rotate them
    for ( index=0 ; index<primeCount ; index++ )
    {
        // If we get to end of calculated primes, break
        if (primes[index] == 0)
            continue;

        // Skip numbers with even digits besides 2
        if ( containsEvenNum(primes[index]) && primes[index] != 2)
            continue;

        // Copy prime and begin rotation
        bool stillPrime = true;
        int rotations = 1;
        int prime = primes[index];
        int rotateMe = rotateDigit(prime);

        // Check if rotation = original number
        while ( rotateMe != prime )
        {
            rotations++;
            // Check if rotation is also prime
            int status = inArray(rotateMe, primes);
            if (status == 0)
            {
                stillPrime = false;
                break;
            }
            // Delete rotated ones so we don't precess them again
            primes[status] = 0;
            rotateMe = rotateDigit(rotateMe);
        }

        // Still prime? Add it
        if (stillPrime == true)
        {
            //printf("Found: %d\n", prime); //debug
            count += rotations;
        }
    }

    printf("Circular primes below %d: %d\n", maxPrime, count);

    return 0;
}
