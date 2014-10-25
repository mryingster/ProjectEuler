// -*- compile-command: "gcc -o problem_055 problem_055.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>

unsigned long long reverse(unsigned long long input)
{
    unsigned long long output=input;
    int index = 0;

    while (output > 0)
    {
        output /= 10;
        index++;
    }

    while (input > 0)
    {
        output += input % 10 * pow(10, --index);
        input /= 10;
    }

    return output;
}

int main()
{
    printf("Project Euler - Problem 55:\n"
           "How many Lychrel numbers are there below ten-thousand?\n\n");

    int number, counter=0;

    for (number=123 ; number<10000 ; number++)
    {
        unsigned long long tmp = reverse(number)+number;
        int tries = 1;

        while (reverse(tmp) != tmp && tries <= 50)
        {
            tmp += reverse(tmp);
            tries++;
        }

        if (reverse(tmp) != tmp)
        {
            // printf("%d %llu is Lychrel (%d)\n", number, tmp, tries); //DEBUG
            counter++;
        }
    }

    printf("Total: %d\n", counter);
    return 0;
}

