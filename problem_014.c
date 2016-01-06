// -*- compile-command: "gcc -std=c99 -o problem_014 problem_014.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int chainLength(unsigned long long index, int *history)
{
    int length = 1;
    while ( index != 1 )
    {
        if (index < 1000000 && index > 0)
            if (history[index] != 0)
            {
                length+=history[index];
                break;
            }
        if ( index % 2 == 0 )
            index = index/2;
        else
            index = 3*index+1;
        length++;
    }

    return length;
}

int main()
{
    printf("Project Euler - Problem 14:\n"
           "Which starting number, under one million, produces the longest chain by following the rules below?\n\n"
           "if n is even, n/2\n"
           "if n is odd, 3n+1\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int history[1000001] = {0};
    int longest[2] = {0};

    for ( int index=1 ; index<=1000000 ; index++ )
        history[index] = chainLength(index, history);

    for ( int index=1 ; index<=1000000 ; index++ )
        if ( history[index] > longest[0] )
        {
            longest[0] = history[index];
            longest[1] = index;
        }

    printf("Starting number: %i, Chain length: %i\n", longest[1], longest[0]);
    printElapsedTime(start);

    return 0;
}
