// -*- compile-command: "gcc -o problem_048 problem_048.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>

unsigned long long bigExponent(const int number)
{
    unsigned long long result = number;
    int counter = number;

    while (counter > 1)
    {
        result *= number;
        result %= 10000000000;
        counter--;
    }

    return result;
}

int main()
{
    printf("Project Euler - Problem 48:\n"
           "Find the last 10 digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.");

    unsigned long long number = 0;
    int index;

    for (index=1; index<=1000; index++)
    {
        number += bigExponent(index);
        number %= 10000000000;
    }

    printf("Last ten digits: %llu\n", number);
    return 0;
}
