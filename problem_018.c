// -*- compile-command: "gcc -std=c99 -o problem_018 problem_018.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 18:\n"
           "Find the maximum total from top to bottom of the triangle below:\n\n");

    int pyramid[15][15]={{75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {95,64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {17,47,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {18,35,87,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {20, 4,82,47,65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {19, 1,23,75, 3,34, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {88, 2,77,73, 7,63,67, 0, 0, 0, 0, 0, 0, 0, 0},
                         {99,65, 4,28, 6,16,70,92, 0, 0, 0, 0, 0, 0, 0},
                         {41,41,26,56,83,40,80,70,33, 0, 0, 0, 0, 0, 0},
                         {41,48,72,33,47,32,37,16,94,29, 0, 0, 0, 0, 0},
                         {53,71,44,65,25,43,91,52,97,51,14, 0, 0, 0, 0},
                         {70,11,33,28,77,73,17,78,39,68,17,57, 0, 0, 0},
                         {91,71,52,38,17,14,91,43,58,50,27,29,48, 0, 0},
                         {63,66, 4,68,89,53,67,30,73,16,69,87,40,31, 0},
                         {04,62,98,27,23, 9,70,98,73,93,38,53,60, 4,23}};
    const int size = sizeof(pyramid)/sizeof(pyramid[0]);

    // Print Pyramid
    for (int y=0; y<size; y++)
    {
        for (int c=size; c>y; c--)
            printf("  ");
        for (int x=0; x<=y; x++)
        {
            printf("%02d  ", pyramid[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    for (int y=size-2; y>=0; y--)
        for (int x=0; x<=y; x++)
        {
            if (pyramid[y+1][x] > pyramid[y+1][x+1])
                pyramid[y][x] += pyramid[y+1][x];
            else
                pyramid[y][x] += pyramid[y+1][x+1];
        }

    printf("%d\n", pyramid[0][0]);
    printElapsedTime(start);

    return 0;
}
