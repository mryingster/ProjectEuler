// -*- compile-command: "gcc -std=c99 -o problem_090 problem_090.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ceuler.h"
#include <stdbool.h>

bool inSet(int d1, int d2, int d3, int d4, int d5, int d6, int num)
{
    if (d1 == num ||
        d2 == num ||
        d3 == num ||
        d4 == num ||
        d5 == num ||
        d6 == num)
        return true;
    return false;
}

bool canDisplay(int d11, int d12, int d13, int d14, int d15, int d16,
                int d21, int d22, int d23, int d24, int d25, int d26)
{
    bool debug = false;

    // Check for each case
    // 01, 04, 09, 16, 25, 36, 49, 64, 81
    int s[9][2] = {{0, 1},
                   {0, 4},
                   {0, 6}, // Representing all 9s as 6
                   {1, 6},
                   {2, 5},
                   {3, 6},
                   {4, 6}, // Representing all 9s as 6
                   {6, 4},
                   {8, 1}};


    // Change all incoming die sides from 9 to 6
    if (d11 == 9) d11 = 6;
    if (d12 == 9) d12 = 6;
    if (d13 == 9) d13 = 6;
    if (d14 == 9) d14 = 6;
    if (d15 == 9) d15 = 6;
    if (d16 == 9) d16 = 6;
    if (d21 == 9) d21 = 6;
    if (d22 == 9) d22 = 6;
    if (d23 == 9) d23 = 6;
    if (d24 == 9) d24 = 6;
    if (d25 == 9) d25 = 6;
    if (d26 == 9) d26 = 6;

    for (int i=0; i<9; i++)
    {
        if (!(inSet(d11, d12, d13, d14, d15, d16, s[i][0]) && inSet(d21, d22, d23, d24, d25, d26, s[i][1])))
            if (!(inSet(d11, d12, d13, d14, d15, d16, s[i][1]) && inSet(d21, d22, d23, d24, d25, d26, s[i][0])))
                return false;

        if (debug == true)
            printf("%d%d: [%d, %d, %d, %d, %d, %d], [%d, %d, %d, %d, %d, %d]\n",
                   s[i][0], s[i][1],
                   d11, d12, d13, d14, d15, d16, d21, d22, d23, d24, d25, d26);
    }

    return true;
}

int main()
{
    printf("Project Euler - Problem 90:\n"
           "How many distinct arrangements of the two cubes allow for all of the square numbers to be displayed?\n\n");

    int num = 0;
    bool debug = false;

    for (int d11 = 5; d11<10;  d11++) // die 1 side 1
        for (int d12 = 4; d12<d11; d12++) // die 1 side 2
            for (int d13 = 3; d13<d12; d13++) // die 1 side 3
                for (int d14 = 2; d14<d13; d14++) // die 1 side 4
                    for (int d15 = 1; d15<d14; d15++) // die 1 side 5
                        for (int d16 = 0; d16<d15; d16++) // die 1 side 6
                            for (int d21 = 5; d21<10;  d21++) // die 2 side 1
                                for (int d22 = 4; d22<d21; d22++) // die 2 side 2
                                    for (int d23 = 3; d23<d22; d23++) // die 2 side 3
                                        for (int d24 = 2; d24<d23; d24++) // die 2 side 4
                                            for (int d25 = 1; d25<d24; d25++) // die 2 side 5
                                                for (int d26 = 0; d26<d25; d26++) // die 2 side 6
                                                    if (canDisplay(d11, d12, d13, d14, d15, d16, d21, d22, d23, d24, d25, d26) == true)
                                                    {
                                                        if (debug == true)
                                                            printf("[%d, %d, %d, %d, %d, %d] [%d, %d, %d, %d, %d, %d]\n",
                                                                   d11, d12, d13, d14, d15, d16, d21, d22, d23, d24, d25, d26);
                                                        num++;
                                                    }

    // Divide by two because each die combination was calculated twice
    printf("Arrangments: %d\n", num/2);
    return 0;
}
