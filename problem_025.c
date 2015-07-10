// -*- compile-command: "gcc -std=c99 -o problem_025 problem_025.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

void copyArray(short to[], short from[], int l)
{
    for (int i=0; i<l; i++)
        to[i] = from[i];
}

void printArray(short a[], int l)
{
    bool nStart = false;
    for (int i=l-1; i>=0; i--)
    {
        if (a[i] != 0) nStart = true;
        if (nStart == true) printf("%d", a[i]);
    }
    printf("\n");
}

void addArray(short to[], short from[], int l)
{
    // Add values
    for (int i=0; i<l; i++)
        to[i] += from[i];

    // Carryover values
    for (int i=0; i<l-1; i++)
        while (to[i] > 9)
        {
            to[i] -= 10;
            to[i+1]++;
        }
}

int main()
{
    printf("Project Euler - Problem 25:\n"
           "What is the index of the first term in the Fibonacci sequence to contain 1000 digits?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int index = 1;
    short a[1000] = {0};
    short b[1000] = {0};
    short c[1000] = {0};
    int l = sizeof(a)/sizeof(short);
    bool debug = false;

    a[0] = 1;
    while (a[l-1] == 0)
    {
        index++;
        copyArray(c, a, l);
        addArray(a, b, l);
        copyArray(b, c, l);

        if (debug == true)
        {
            printf("%d ", index);
            printArray(a, l);
        }
    }

    printf("Total: %d\n", index);
    printElapsedTime(start);

    return 0;
}
