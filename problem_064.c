// -*- compile-command: "gcc -o problem_064 problem_064.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Project Euler - Problem 64:\n"
           "How many continued fractions for N <= 10000 have an odd period?\n\n");

    int number = 0, count = 0;
    while (++number < 10000)
    {
        int a0 = sqrt(number);
        if (a0 * a0 == number) continue;

        int period = 0;
        int d = 1;
        int m = 0;
        int a = a0;

        while ( a != a0 * 2)
        {
            m = d*a - m;
            d = (number - m * m) / d;
            a = (a0 + m) /d;
            period++;
        }


        if (period %2 != 0) count++;
    }

    printf("Fractions with odd period: %d\n", count);
    return 0;
}
