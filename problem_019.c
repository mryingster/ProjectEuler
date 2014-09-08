// -*- compile-command: "gcc -o problem_019 problem_019.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    printf("Project Euler - Problem 19:\n"
           "Find the total number of Sundays that fell on the first of the month in the 20th Century.\n\n");

    int dayOfWeek = 2;    // 1/1/1901 Started on a Tuesday. 0 = Sunday, 1 = Monday, 2 = Tuesday, etc.
    int year      = 1901;
    int month     = 1;    // 1 = January, 2 = February, etc.
    int day       = 1;
    int sum       = 0;


    while ( year <= 2000 )
    {
        if ( dayOfWeek % 7 == 0 && day == 1 )
        {
            sum++;
            //printf("%i/%i/%i\n", month, day, year); // Debug
        }

        //Increment date
        day++;
        dayOfWeek++;

        // Increments Days appropriately
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            if (day == 32)
                day = 1;
        if (month == 4 || month == 6 || month == 9 || month == 11)
            if (day == 31)
                day = 1;
        if (month == 2)
        {
            if (year % 4)
            {
                if (day == 29)
                    day = 1;
            }
            else
            {
                if (day == 30)
                    day = 1;
            }
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

    printf("Total Mondays: %i\n", sum);

    return 0;
}
