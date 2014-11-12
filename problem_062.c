// -*- compile-command: "gcc -o problem_062 problem_062.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

unsigned numSignature(unsigned long long number)
{
    unsigned out = 0;
    while (number > 0)
    {
        out += 1 * pow(10, number % 10);
        number /= 10;
    }
    return out;
}

int main(){
    printf("Project Euler - Problem 62:\n"
           "Find the smallest cube for which exactly five permutations of its digits are cube.\n\n");

    unsigned results[10000] = {};

    // Get Signatures for powers of 3
    int i = 0;
    for (i=2 ; i<10000 ; i++)
        results[i] = numSignature(pow(i,3));

/*
    // DEBUG - Print Table
    for (i=2 ; i<10000 ; i++)
        printf("%llu\n", results[i]);
*/

    // Search Results for signatures that are same
    for (i=0 ; i<10000 ; i++)
    {
        int n, count=0;
        for (n=0 ; n<10000 ; n++)
            if (results[n] == results[i])
                count++;
        if (count == 5)
            break;
    }

    printf("%d^3 = %lu\n", i, (unsigned long)pow(i, 3));
    return 0;
}


