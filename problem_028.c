// -*- compile-command: "gcc -o problem_028 problem_028.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    printf("Project Euler - Problem 28:\n"
           "Starting with the number 1 and moving to the right in a clockwise direction, form a 1001 by 1001 spiral. What is the sum of the numbers on the diagonals in this spiral?\n\n");

    int sum        = 0;
    int sideLength = 1001;
    int spiralSize = sideLength * sideLength;
    int position   = 0;
    int skipAmount = 1;
    int side       = 0;

    for (position=1 ; position<=spiralSize ; position++)
    {
        //printf("%d\n",position); // Debug
        sum += position;
        position += skipAmount;

        // Skip 2 positions every time we go around all 4 sides
        side++;
        if ( side % 4 == 0)
            skipAmount += 2;
    }

    printf("Sum: %d\n", sum);

    return 0;
}
