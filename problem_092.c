// -*- compile-command: "gcc -std=c99 -o problem_092 problem_092.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 92:\n"
           "A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before. How many starting numbers below ten million will arrive at 89?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int count = 0;
    long limit = 10000000;
    short *history = malloc(limit*sizeof(short));

    for (long n=1; n<limit; n++)
    {
        long number = n;
        while (number != 1 && number != 89)
        {
            long newNumber = 0;
            while (number > 0)
            {
                newNumber += pow(number % 10, 2);
                number /= 10;
            }
            number = newNumber;
            if (history[number] == 1) number = 1;
            if (history[number] == 89) number = 89;
        }

        switch (number) {
        case 1:
            history[n] = 1;
            break;
        case 89:
            history[n] = 89;
            count++;
            break;
        }
    }

    printf("Total: %d\n", count);
    printElapsedTime(start);

    free(history);
    return 0;
}
