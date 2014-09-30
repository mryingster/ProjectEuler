// -*- compile-command: "gcc -o problem_002 problem_002.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Project Euler - Problem 2:\n"
           "By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\n\n");

    int previousNum = 0, nextNum = 0, currentNum = 1;
    int total = 0;

    while (true)
    {
        nextNum = previousNum + currentNum;
        previousNum = currentNum;
        currentNum = nextNum;
        if ( currentNum >= 4000000 )
            break;
        if ( currentNum % 2 == 0)
            total += currentNum;
       }

    printf("Sum: %d\n", total);

    return 0;
}
