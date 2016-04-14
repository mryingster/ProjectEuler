// -*- compile-command: "gcc -std=c99 -o problem_024 problem_024.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

void nextPermutation(int a[], const int len)
{
    // Find the largest index k such that a[k] < a[k + 1]
    int k = 0;
    for (int i = 0; i<len-1; i++)
        if (a[i] < a[i+1])
            k = i;

    // Find the largest index l greater than k such that a[k] < a[l]
    int l = 0;
    for (int i=k; i<len; i++)
        if (a[k] < a[i])
            l = i;

    // Swap the value of a[k] with that of a[l]
    int t = a[k];
    a[k] = a[l];
    a[l] = t;

    // Reverse the sequence from a[k + 1] up to and including the final element a[n]
    if (k < 8)
    {
        int r[10] = {0};
        int j = 9;
        for (int i=k+1; i<len; i++)
        {
            r[j] = a[i];
            j -= 1;
        }
        for (int i=(k+1); i<len; i++)
            a[i] = r[i];
    }
}

void printArray(int a[], int l)
{
    for (int i=0; i<l; i++)
        printf("%d", a[i]);
    printf("\n");
}

int main()
{
    printf("Project Euler - Problem 24:\n"
           "Find the 1,000,000th lexiconic permutation of the numbers 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(array)/sizeof(array[0]);

    for (int i=0; i<1000000; i++)
        nextPermutation(array, length);

    printArray(array, length);
    printElapsedTime(start);

    return 0;
}
