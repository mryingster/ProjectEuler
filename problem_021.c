// -*- compile-command: "gcc -o problem_021 problem_021.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main()
{
    printf("Project Euler - Problem 21:\n"
           "Evaluate the sum of all the amicable numbers under 10000.\n\n");

    int number     = 0;
    int divisorSum = 0;
    int divisor    = 0;
    int sum        = 0;
    short history[10001] = {0};

    for (number=1 ; number<10001 ; number++)
    {
        divisorSum=0;

        // Find sum of divisors
        for (divisor=1 ; divisor<number ; divisor++)
            if (number % divisor == 0)
            {
                //printf("%d divisible by %d\n", number, divisor); // DEBUG
                divisorSum += divisor;
            }

        // Ignore sums larger than 10000
        if ( divisorSum > 10000 )
            continue;

        // Check if amicable
        if (history[divisorSum] == number)
        {
            //printf("Amicable pair %d %d\n", number, divisorSum); // DEBUG
            sum += number + divisorSum;
        }

        // Record divisor sum
        history[number]=divisorSum;
    }

    printf("Sum: %d\n", sum);

    return 0;
}
