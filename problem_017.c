// -*- compile-command: "gcc -std=c99 -o problem_017 problem_017.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 17:\n"
           "If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    const int thousand = 8;
    const int hundred  = 7;
    const int and      = 3;
    const int onesToNums[10]  = {0,3,3,5,4,4,3,5,5,4};
    const int tensToNums[10]  = {0,0,6,6,5,5,5,7,6,6};
    const int teensToNums[10] = {3,6,6,8,8,7,7,9,8,8};

    int i = 0;
    int total = 0;

    for (i=1 ; i<=1000 ; i++)
    {
        int ones      = i%10;
        int tens      = i/10%10;
        int hundreds  = i/10/10%10;
        int thousands = i/10/10/10%10;

        if (thousands != 0)
            total += thousand + onesToNums[thousands];

        if (hundreds != 0)
        {
            if (tens == 0 && ones == 0)
                total += hundred + onesToNums[hundreds];
            else
                total += hundred + and + onesToNums[hundreds];
        }

        if (tens != 0)
        {
            if (tens == 1)
                total += teensToNums[ones];
            else
                total += tensToNums[tens];
        }

        if (tens != 1)
            total += onesToNums[ones];
    }

    printf("Total letters used: %i\n", total);
    printElapsedTime(start);

    return 0;
}
