// -*- compile-command: "gcc -o problem_020 problem_020.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    printf("Project Euler - Problem 20:\n"
           "Find the sum of the digits in the number 100!\n\n");

    int bigNum[1000] = {0};
    int index = 0;
    int factorial = 0;
    int sum = 0;

    bigNum[997]=1; // Starting value is 100

    for (factorial=99 ; factorial>0 ; factorial--)
    {
        // Multiply by factorial
        for (index=999 ; index>=0 ; index--)
            bigNum[index] *= factorial;

        // Carry-over each element if needed
        for (index=999 ; index>=0 ; index--)
            while (bigNum[index] > 9)
            {
                bigNum[index]   -= 10;
                bigNum[index-1] += 1;
            }

        /*
        // DEBUG - Print each element
        for (index=0 ; index<1000 ; index++)
            printf("%i",bigNum[index]);
        printf("\n");
        */
    }

    for (index=0 ; index<1000 ; index++)
        sum += bigNum[index];

    printf("Sum: %i\n", sum);

    return 0;
}
