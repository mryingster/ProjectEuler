// -*- compile-command: "gcc -o problem_039 problem_039.c -Wall -O3" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>

bool isTriangle(int a, int b, int c)
{
    if ( (a*a) == (b*b) + (c*c) ||
         (b*b) == (a*a) + (c*c) ||
         (c*c) == (a*a) + (b*b) )
        return true;
    return false;
}

int main()
{
    printf("Project Euler - Problem 39:\n"
           "Find the perimeter of a right triangle (p) that has the most possible solutions, where the perimiter is less than or equal to 1000.\n\n");

    int a, b, c, p;
    int maxCount = 0;
    int maxPerimeter = 0;
    int count=0;

    for ( p=13 ; p<=1000 ; p++ )
    {
        count = 0;
        a = 0;

        // Increment side A
        while (++a < p - 2)
        {
            b = 0;
            // Increment side B, remainder is side C
            while ((c = p - a - (++b)) > 0)
            {
                // If we pass the pythagorus test, it's a right triangle!
                if ( isTriangle (a, b, c) == true)
                {
                    //printf("Solution: %d, %d, %d\n", a, b, c); // DEBUG
                    count++;
                }
            }
        }

        count /= 6; // Each solution is found 6 times

        // Check if current solution is better than previous best
        if (count > maxCount)
        {
            maxCount = count;
            maxPerimeter = p;
        }
    }

    printf("Greatest: %d, (%d solutions)\n", maxPerimeter, maxCount);

    return 0;
}
