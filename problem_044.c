// -*- compile-command: "gcc -o problem_044 problem_044.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPentagonal(int number)
{
    long double check = (sqrt(24*number+1)+1)/6;
    int check2 = check;
    if (check == check2) return true;
    return false;
}

int main()
{
    printf("Project Euler - Problem 44:\n"
           "Find the smallest pair of pentagonal numbers whose sum and difference is pentagonal.\n\n");

    const int searchLevel = 3000;
    int pentarray[searchLevel];

    int index  = 0;
    int index2 = 0;
    int found  = 0;

    // Zero out the pentarray
    for (index = 0; index < searchLevel; index++) pentarray[index] = 0;

    // Increment our pentarray of pentagonal numbers, and work with each as it is calculated
    for (index = 0; index <= searchLevel; index++)
    {
        // Record new pentagonal number to pentarray
        pentarray[index] = index * (3*index-1) / 2;

        // Sum is current maximum number
        int sum = pentarray[index];

        for (index2 = index-1; index2 > 0; index2--)
        {
            // Decrement through pentarray array for pentagonal number 1
            int pent1 = pentarray[index2];

            // Search if pent2 is pentagonal
            int pent2 = abs(sum - pent1);
            if (isPentagonal(pent2) == false)
                continue;

            // Check if difference is pentagonal
            int diff = abs(pent2 - pent1);
            if (isPentagonal(diff) == false)
                continue;

            //If we made it this far, we have an answer
            //printf("Sum: %d, Pent1: %d, Pent2: %d, Diff: %d\n", sum, pent1, pent2, diff); //DEBUG
            found = diff;
            break;
        }
        if (found != 0) break;
    }
    printf("Smallest difference: %d", found);

    return 0;
}
