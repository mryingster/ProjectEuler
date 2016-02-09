// -*- compile-command: "gcc -std=c99 -o problem_027 problem_027.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"
int main()
{
    printf("Project Euler - Problem 27:\n"
           "Find the product of the coefficients, a and b, for the quadratic expression, n^2 + an + b, that produces the maximum number of primes for consecutive values of n, starting with n = 0.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int answer[3] = {};
    for (int a=-1000 ; a<1000 ; a++)
    {
        for (int b=-1000 ; b<1000 ; b++)
	{
            int count = 0;
            for (int n=0 ; n<100 ; n++)
	    {
                // Use formula, n^2 + an + b, to get answer
                int answer = (n*n)+(n*a)+b;
                if (isPrime(answer) == true)
                    count++;
                else
                    break;
            }

            // Keep track of best performers
            if (count > answer[0])
            {
                answer[0]=count;
                answer[1]=a;
                answer[2]=b;
            }
	}
    }

    printf("Solution: a:%d, b:%d, Product: %d (produces %d primes)\n",
           answer[1], answer[2], answer[1]*answer[2], answer[0]);
    printElapsedTime(start);

    return 0;
}

