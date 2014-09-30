// -*- compile-command: "gcc -o problem_005 problem_005.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int number = 1000;
    int divisor;
    bool candidate;

    printf("Project Euler - Problem 5:\n"
           "What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n\n");

    while ( number += 20 )
    {
        candidate = true;
        for ( divisor=2 ; divisor<=20 ; divisor++ )
        {
            if ( number % divisor != 0 )
            {
                candidate = false;
                break;
            }
        }
        if ( candidate == true )
            break;
    }

  printf("Smallest number: %d\n", number);

  return 0;
}

