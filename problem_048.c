// -*- compile-command: "gcc -o problem_048 problem_048.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Project Euler - Problem 48:\n"
           "Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.\n\n");

    unsigned long long total  = 0;
    int index;

    for (index=1; index<=1000; index++)
    {
        unsigned long long number = 1;
        int counter = index;

        while (counter > 0)
        {
            number *= index;
            number %= 10000000000;
            counter--;
        }

        total += number;
        total %= 10000000000;
    }

    printf("Last ten digits: %llu\n", total);
    return 0;
}
