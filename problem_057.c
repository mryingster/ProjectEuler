// -*- compile-command: "gcc -o problem_057 problem_057.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    printf("Project Euler - Problem 57:\n"
           "In the first one-thousand expansions of 1+1/(2+1/(2+1/(2+...)))=1.414213, how many fractions contain a numerator with more digits than denominator?\n\n");

    int num[1000] = {3}, num_old[1000] = {1}, num_older[1000] = {3};
    int den[1000] = {2};
    int counter = 0, topheavy = 0;

    while ( counter++ < 1000 )
    {
        int index;
        // Update numbers
        for ( index=0 ; index<1000 ; index++ )
        {
            den[index] += num[index];
            num_older[index] = num_old[index];
            num_old[index] = num[index];
            num[index] = num[index] * 2 + num_older[index];
        }

        // Roll over values
        for ( index=0 ; index<1000 ; index++ )
        {
           while ( num[index] > 9 )
            {
                num[index]   -= 10;
                num[index+1] += 1;
            }

            while ( den[index] > 9 )
            {
                den[index]   -= 10;
                den[index+1] += 1;
            }
        }

        // Count digits
        int num_count=1000, den_count=1000;
        while(num[--num_count] == 0);
        while(den[--den_count] == 0);

        // Check if topheavy
        if ( num_count > den_count ) topheavy++;

/*
        // DEBUG - Print Fractions
        for (index=num_count-1; index >= 0; index--)
            printf("%d", num[index]);
        printf(" / ");
        for (index=num_count-1; index >= 0; index--)
            printf("%d", den[index]);
        printf("\n");
*/

    }

    printf("Total: %d\n", topheavy);
    return 0;
}
