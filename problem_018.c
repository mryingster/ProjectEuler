// -*- compile-command: "gcc -std=c99 -o problem_018 problem_018.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
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
    int binaryPath[16] = {0};
    int largest = 0;
    bool debug = false;

    printf("Project Euler - Problem 18:\n"
           "Find the maximum total from top to bottom of the triangle below:\n\n");

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

    while (binaryPath[0] != 1)
    {
        // Carry over addition
        for (int i=size ; i>=0 ; i--)
            if (binaryPath[i]>1)
            {
                binaryPath[i] -= 2;
                binaryPath[i-1]++;
            }

        // Follow Path
        int candidate = 0, n = 0;
        for (int i=size ; i>0 ; i--)
	{
            if (binaryPath[i] == 1)
                n += 1;
            candidate += pyramid[size-i][n];
	}

        // DEBUG: Print path and sum
        if (debug == true)
        {
            for (int i=0 ; i<16 ; i++)
                printf("%d", binaryPath[i]);
            printf(" - %d\n", candidate);
        }

        // Compare if larger
        if (candidate > largest)
            largest = candidate;

        // Increase binaryPath by 1
        binaryPath[size]++;
    }

    printf("Largest sum: %d\n", largest);
    printElapsedTime(start);

    return 0;
}
