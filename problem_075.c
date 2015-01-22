// -*- compile-command: "gcc -std=c99 -o problem_075 problem_075.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <math.h>

int gcd(int n, int d)
{
    int gcd = 1;
    for (int i=2; i<d; i++)
        if (n % i == 0 && d % i == 0)
            gcd = i;
    return gcd;
}

int main()
{
    printf("Project Euler - Problem 75:\n"
           "Given that L is the length of the wire, for how many values of L ≤ 1,500,000 can exactly one integer sided right angle triangle be formed?\n\n");

    int limit = 1500000;
    int sqr_limit = sqrt(limit/2);
    int history[1500000] = {};

    for (int m=2; m<sqr_limit; m++)
        for (int n=1; n<m; n++)
        {
            // Euclid's Formula:
            // If sides m and n add up to be odd and the greatest common
            // denominator of n/m is 1 then we have a pythagorean triple
            if ( (m+n) % 2 == 1 && gcd(n, m) == 1)
            {
                int a = (m*m) - (n*n);
                int b = 2 * m * n;
                int c = (m*m) + (n*n);
                int L = a + b + c;
                //printf("%d: %d, %d, %d\n", p, a, b, c); // DEBUG
                while (L < limit)
                {
                    history[L]++;
                    L += a + b + c;
                }
            }
        }

    // Count results
    int count = 0;
    for (int i=0; i<limit; i++)
        if (history[i] == 1) count++;

    printf("Total: %d\n", count);

    return 0;
}
