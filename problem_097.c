// -*- compile-command: "gcc -std=c99 -o problem_097 problem_097.c -Wall ceuler.c -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 97\n");
    printf("Find the last ten digits of the prime number, 28433×(2^7830457)+1.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int array[10] = {0};
    int exponent = 7830457; // 2's exponent
    array[9]=28433;         // Starting value
    bool debug = false;

    //Perform exponent multiplication
    for (int i=1; i<=exponent; i++)
    {
        // Multiply each element by 2
        for (int n=0; n<10; n++)
            array[n] *= 2;

        // Carry over number for big cells
        for (int j=9; j>0; j--)
            while (array[j] >= 10)
            {
                array[j-1]++;
                array[j] -= 10;
            }
        while (array[0] >= 10)
            array[0] -= 10;

        // Debug - Print array
        if (debug == true)
        {
            for (int j=0; j<10; j++)
                printf("%d", array[j]);
            printf("\n");
        }
    }

    array[9]++;  // Add one!

    //Print array
    for (int j=0; j<10; j++)
        printf("%d", array[j]);
    printf("\n");
    printElapsedTime(start);

    return 0;
}
