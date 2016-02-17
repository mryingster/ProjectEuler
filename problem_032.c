// -*- compile-command: "gcc -std=c99 -o problem_032 problem_032.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

bool isPandigitalProduct(int a, int b, int c)
{
    // Create check array for digits. Mark 0 as 1 since 0 not included in pandigital numbers
    int check[10] = {0};
    check[0] = 1;

    while (a != 0)
    {
        check[a%10]++;
        a /= 10;
    }

    while (b != 0)
    {
        check[b%10]++;
        b /= 10;
    }

    while (c != 0)
    {
        check[c%10]++;
        c /= 10;
    }

    for (int i=0; i<10; i++)
        if (check[i] != 1)
            return false;

    return true;
}

int main()
{
    printf("Project Euler - Problem 32:\n"
           "Find the sum of all numbers that can be written as pandigital products.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int sum = 0;
    int found[100] = {};
    int count = 0;
    bool debug = false;

    for (int a=1 ; a<2500; a++)
        for (int b=a ; b<2500; b++)
        {
            int c = a*b;

            // If pandigital, record, increment
            if (isPandigitalProduct(a, b, c) == true)
            {
                // Check history for c
                bool recorded = false;
                for (int i=0 ; i<count ; i++)
                    if (found[i] == c)
                        recorded = true; //Already recorded, ignore

                //Record and add to sum
                if (recorded == false)
                {
                    if (debug == true) printf("%d x %d = %d\n", a, b, c);
                    found[count++]=c;
                    sum += c;
                }
            }
        }

    printf("%d\n", sum);
    printElapsedTime(start);

    return 0;
}
