// -*- compile-command: "gcc -o problem_023 problem_023.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int getDivisorSum(int number)
{
    int index=0, sum=0;

    for (index=1 ; index<number ; index++)
        if (number % index == 0)
            sum += index;
    return sum;
}

int main()
{
    printf("Project Euler - Problem 23:\n"
           "Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.\n\n");

    int number     = 0;
    int divisorSum = 0;
    int counter    = 0;
    int abundant[28123] = {0};
    int abun1      = 0;
    int abun2      = 0;
    unsigned long long sum = 0;

    // Find abundant numbers and store in array, adundant
    for (number=1 ; number<=28123 ; number++)
    {
        divisorSum = getDivisorSum(number);
        if (divisorSum > number)
        {
            abundant[counter]=number;
            counter++;
        }
    }

    int invalid = 0;
    // See if number is made up of two abundant numbers
    for (number = 0 ; number <= 28123 ; number++)
    {
        invalid = 0;
        for (abun1=0 ; abun1<counter ; abun1++)
        {
            for (abun2=abun1 ; abun2<counter ; abun2++)
            {
                if (abundant[abun1] + abundant[abun2] > number)
                    break;

                if (abundant[abun1] + abundant[abun2] == number)
                {
                    invalid = 1;
                    break;
                }
            }
            if (invalid == 1)
                break;
        }
        if (invalid != 1)
        {
            sum += number;
            //printf("Number not made of abundant pairs: %d, sum: %llu\n", number, sum); // DEBUG
        }
    }

    printf("Sum: %llu\n", sum);
    return 0;
}
