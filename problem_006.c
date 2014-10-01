// -*- compile-command: "gcc -o problem_006 problem_006.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    int number = 0, sumsquares = 0, squaresums = 0, result = 0;

    printf("Project Euler - Problem 6:\n"
           "Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n\n");

    for (number=1 ; number<=100 ; number++)
        squaresums += number;

    squaresums *= squaresums;

    for (number=1 ; number<=100 ; number++)
        sumsquares += (number * number);

    //printf("%d %d\n", squaresums, sumsquares); // DEBUG

    result = squaresums-sumsquares;

    printf("Difference: %d\n", result);

    return 0;
}

