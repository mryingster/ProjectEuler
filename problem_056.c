// -*- compile-command: "gcc -o problem_056 problem_056.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main ()
{
    printf("Project Euler - Problem 56:\n"
           "Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?\n\n");

    int bigArray[200];
    int index, a, b, biggestsum=0;

    for (a=1 ; a<100 ; a++)
    {
        for (b=1 ; b<100 ; b++)
        {
            // Clear out array
            for (index=0; index<200; index++) bigArray[index] = 0;

            // Seed the array
            bigArray[0] = a;

            // Multiply by a b times
            int multiplications = b;
            while (multiplications-- >= 0)
            {
                // Multiply each element by a
                for (index=0; index<200; index++)
                    bigArray[index] *= a;

                // carry over elements
                for (index=0; index<200; index++)
                    while (bigArray[index] > 9)
                    {
                        bigArray[index]   -= 10;
                        bigArray[index+1] += 1;
                    }
            }

            // Sum of numbers
            int sum = 0;
            for (index=0; index<200; index++)
                sum += bigArray[index];

            //printf("sum of %d^%d=%d\n", a, b, sum);

            // See if larger than max
            if (biggestsum < sum)
                biggestsum = sum;
        }
    }
    printf("Biggest digital sum = %d\n", biggestsum); //972
    return 0;
}
