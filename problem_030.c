// -*- compile-command: "gcc -o problem_030 problem_030.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>

int main()
{
    int fifthPowers[10] = {0};
    int currentNumber = 0;
    int currentSum = 0;
    int index = 0;
    int sum = 0;

    printf("Project Euler - Problem 30:\n"
           "Find the sum of all the numbers that can be written as the sum of fifth powers of their digits\n\n");

    // Populate Fifth Powers Array
    for ( index=1 ; index<10 ; index++ )
        fifthPowers[index] = pow(index, 5);

    // Can't be larger than 354294 (6*9^5)
    for ( index=2 ; index < 355000; index++ )
    {
        currentNumber = index;
        currentSum = 0;

        // Decompose number
        while (currentNumber > 0)
        {
            currentSum += fifthPowers[currentNumber % 10];
            currentNumber /= 10;
        }

        // Check sum against number
        if (currentSum == index)
        {
            //printf("index: %d, sum:%d\n", index, currentSum); //DEBUG
            sum += index;
        }
    }

    printf("Sum: %d\n", sum);

    return 0;
}
