// -*- compile-command: "gcc -std=c99 -o problem_086 problem_086.c -Wall -lm -03" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    printf("Project Euler - Problem 86:\n"
           "Find the least value of M such that the number of integer solutions for a cuboid smaller than M x M x M first exceeds one million.\n\n");

    // Generate all cuboids M x M x M until we get answer > limit
    int limit = 1000000;
    int solutions = 0;
    int M = 0;
    bool debug = false;

    for(int a=1; a<=1000000; a++)
    {
        if (debug == true)
        {
            printf("%d (%d)\r", a, solutions);
            fflush(stdout);
        }

        for(int b=1; b<=a; b++)
        {
            for(int c=1; c<=b; c++)
            {
                // Find Shortest Solution
                double shortest = sqrt(pow(a,2) +  pow(b+c, 2));
                double path2    = sqrt(pow(b,2) +  pow(a+c, 2));
                double path3    = sqrt(pow(c,2) +  pow(b+a, 2));

                if (path2 < shortest)
                    shortest = path2;
                if (path3 < shortest)
                    shortest = path3;

                if (debug == true)
                    printf("%d x %d x %d --> %f\n", a, b, c, shortest);

                // If it is integer solution
                if (shortest == (int)shortest) solutions++;
                if (solutions >= limit) break;
            }
            if (solutions >= limit) break;
        }
        if (solutions >= limit)
        {
            M = a;
            break;
        }
    }

    printf("Smallest M for which solutions first exceed %d: %d\n", limit, M);
    return 0;
}
