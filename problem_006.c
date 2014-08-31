// -*- compile-command: "gcc -o problem_006 problem_006.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    int i, j, sumsquares, squaresums, candidate;

    printf("Project Euler - Problem 6:\n"
           "Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n\n");

    squaresums=sumsquares=0;

    for (i=1 ; i<101 ; i++)
        squaresums=squaresums+i;
    squaresums=squaresums*squaresums;

    for (j=1 ; j<101 ; j++)
        sumsquares=sumsquares+j*j;

    //printf("%i %i\n", squaresums, sumsquares);

    candidate=squaresums-sumsquares;

    printf("Difference: \033[1m%i\033[0m\n", candidate);

    return 0;
}

