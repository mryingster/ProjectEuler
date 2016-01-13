// -*- compile-command: "gcc -std=c99 -o problem_019 problem_019.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 19:\n"
           "Find the total number of Sundays that fell on the first of the month in the 20th Century.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int weekDay = 2;    // 1/1/1901 Started on a Tuesday. 0 = Sunday, 1 = Monday, 2 = Tuesday, etc.
    int year    = 1901;
    int month   = 1;    // 1 = January, 2 = February, etc.
    int day     = 1;
    int sum     = 0;
    bool debug  = false;

    while ( year < 2001 )
    {
        if ( weekDay % 7 == 0 && day == 1 )
        {
            sum++;
            if (debug == true) printf("%2d/%d/%d\n", month, day, year); // Debug
        }

        //Increment date
        day++;
        weekDay++;

        // Increments Days appropriately for given month
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 32)
                day = 1;

        if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
                day = 1;

        if (month == 2)
        {
            if (year % 4 && day == 29)
                day = 1;

            else if (day == 30)
                day = 1;
        }

        // Increments Months and Years appropriately
        if (day == 1)
            month++;

        if (month == 13)
        {
            month = 1;
            year++;
        }
    }

    printf("%d\n", sum);
    printElapsedTime(start);

    return 0;
}
