// -*- compile-command: "gcc -o problem_015 problem_015.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    printf("Project Euler - Problem 15:\n"
           "Starting in the top left corner in a 20 by 20 grid, how many routes are there to the bottom right corner?\n\n");

    unsigned long long pascal[100][100] = {0};
    int n = 0, i = 0;

    pascal[0][0]=1;

    while (i < 40)
    {
        i++;
        for (n=0 ; n<100 ; n++)
            if (n-1 < 0)
                pascal[i][n]=pascal[i-1][n];
            else
                pascal[i][n]=pascal[i-1][n]+pascal[i-1][n-1];

        /*
        // DEBUG - Print row
        printf("%2i: ", i);
        for (n=0 ; n<100 ; n++)
            if (pascal[i][n]==0)
                break;
            else
                printf("%6llu ", pascal[i][n]);
        printf("\n\n");
        */

    }

    printf("Answer: %llu\n", pascal[40][20]);

    return 0;
}
