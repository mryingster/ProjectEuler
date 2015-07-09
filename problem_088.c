// -*- compile-command: "gcc -std=c99 -o problem_088 problem_088.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ceuler.h"

void printArray(int a[], int l)
{
    for (int i=0; i<l; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void processArray(int *a, int l, int limit, unsigned long long *k, unsigned long long *p)
{
    unsigned long long sum = 0;
    // Go from left to right
    for (int i=0; i<l; i++)
    {
        // Keep track of sum/product/k
        sum += a[i];
        *p = *p * a[i];
        *k = *p - sum + i+1;

        // If we hit a that is 1
        if (a[i] == 1)
        {
            // Increment the number
            a[i]++;

            // Get out of here!
            break;
        }

        // If we hit end of array, work backwards to increment
        if (i == l-1)
        {
            for (int j=i; j>=0; j--)
            {
                if (j == 0 || a[j] < a[j-1])
                {
                    a[j]++;
                    break;
                }
                else
                    a[j] = 1;
            }
            break;
        }

        // If we get out of bounds
        if (*k > limit)
        {
            // Backtrack to next different number
            while (i != 0 && a[i] >= a[i-1])
                i--;
            // Increment number
            a[i]++;

            // Reset all numbers to right to 1
            while (++i<l)
                a[i] = 1;

            // Get out of here
            break;
        }
    }
}

int main()
{
    printf("Project Euler - Problem 88:\n"
           "What is the sum of all the minimal product-sum numbers for 2<=k<=12000?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    unsigned long long sum = 0;
    bool debug = false;

    // K values stored
    int kLimit = 12000+1;
    unsigned long long kArray[kLimit];
    for (int i=0; i<kLimit; i++) kArray[i]=0;

    // Factors used in computation of K
    int fLimit = 14;
    int factors[fLimit];
    for (int i=0; i<fLimit; i++) factors[i]=1;
    factors[0] = 2;

    while (factors[0] < kLimit)
    {
        unsigned long long product = 1;
        unsigned long long ksum = 0;
        processArray(factors, fLimit, kLimit, &ksum, &product);

        if (ksum <= kLimit)
        {
            // Print results
            if (debug == true)
                printf("k=%llu: %llu\n", ksum, product);

            // Record results
            if (kArray[ksum] == 0 || kArray[ksum] > product)
                kArray[ksum] = product;

        }
    }

    for (int i=2; i<kLimit; i++)
    {
        // Print results
        if (debug == true)
            printf("k=%d: %llu\n", i, kArray[i]);

        // Look for unique results
        bool add = true;
        for (int j=2; j<i; j++)
            if (kArray[i] == kArray[j])
            {
                add = false;
                break;
            }

        // Keep track of sum
        if (add == true)
            sum += kArray[i];
    }

    printf("Sum: %llu\n", sum);
    printElapsedTime(start);

    return 0;
}
