// -*- compile-command: "gcc -o problem_065 problem_065.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>

void copyArray(int a1[], int a2[], int length)
{
    int index;
    for (index=0; index<length; index++)
        a2[index] = a1[index];
}

void carryArray(int a[], int length)
{
    int index;
    for (index=0; index<length; index++)
        while (a[index] > 9)
        {
            a[index]   -= 10;
            a[index+1] += 1;
        }
}

int countArray(int a[], int length)
{
    int count=0, index;
    for (index=0; index<length; index++)
        count += a[index];
    return count;
}

int main()
{
    printf("Project Euler - Problem 65:\n"
           "Find the sum of digits in the numerator of the 100th convergent of the continued fraction for e.\n\n");

    int count = 1;
    int multiplier = 0;
    int numerator_new[100] = {2};
    int numerator_cur[100] = {1};
    int numerator_old[100] = {0};
    int length = sizeof(numerator_new) / sizeof(numerator_new[0]);

    while (count++ < 100)
    {
        //Copy arrays from new to cur, and cur to old
        copyArray(numerator_cur, numerator_old, length);
        copyArray(numerator_new, numerator_cur, length);

        // Multiply by special multiplier every third time
        int multiplier_cur = 1;
        if (count % 3 == 0)
        {
            multiplier += 2;
            multiplier_cur = multiplier;
        }

        // Process new array
        int index;
        for (index=0; index<length; index++)
            numerator_new[index] = numerator_cur[index] * multiplier_cur + numerator_old[index];
        carryArray(numerator_new, length);
    }

    printf("%d\n", countArray(numerator_new, length));
    return 0;
}
