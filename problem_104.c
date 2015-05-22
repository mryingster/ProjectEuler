// -*- compile-command: "gcc -std=c99 -o problem_104 problem_104.c -Wall" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPanDigital(long number, bool beginning)
{
    // Get down to size if we are chekcing left-most digits
    if (beginning == true)
        while (number > 999999999)
            number /= 10;

    int n[9] = {};

    for (int i=0; i<9; i++)
    {
        int t = number % 10 - 1;
        if (t < 0) return false;
        n[t]++;
        number /= 10;
        if (n[t] > 1) return false;
    }

    return true;
}

int main()
{
    unsigned long long numEnd[3]   = {1, 1, 1};
    unsigned long long numStart[3] = {1, 1, 1};
    int count = 2;
    bool debug = false;

    printf("Project Euler - Problem 104:\n"
           "Given that Fk is the first Fibonacci number for which the first nine digits and the last nine digits are 1-9 pandigital, find k.\n\n");

    while (true)
    {
        count++;

        // Evaluate the fibonacci number for the last 9 digits
        numEnd[1] =  numEnd[0];
        numEnd[0] += numEnd[2];
        numEnd[2] =  numEnd[1];

        // Keep only last 9 digits
        if (numEnd[0] > 1000000000)
        {
            numEnd[0] %= 1000000000;
            numEnd[2] %= 1000000000;
        }

        // Evaluate the fibonacci number for the first 9 digits
        numStart[1] =  numStart[0];
        numStart[0] += numStart[2];
        numStart[2] =  numStart[1];

        // Keep only enough digits for LLU.
        while (numStart[0] > 1000000000000000000)
        {
            numStart[0] /= 10;
            numStart[2] /= 10;
        }

        // Check if it is pandigital
        if (isPanDigital(numStart[0], true))
        {
            if (debug == true) printf("(B) %d %llu\n", count, numStart[0]);
            if (isPanDigital(numEnd[0], false))
            {
                if (debug == true) printf("(E) %d %llu\n", count, numEnd[0]);
                break;
            }
        }
    }

    printf("k = %d\n", count);

    return 0;
}
