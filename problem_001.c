// -*- compile-command: "gcc -o problem_001 problem_001.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    int number, total = 0;

    printf("Project Euler - Problem 1:\n"
           "Find the sum of all the multiples of 3 or 5 below 1000.\n\n");

   for ( number=0 ; number<1000 ; number++ )
   {
       if ( number % 3 == 0 )
           total += number;
       else
           if ( number % 5 == 0 )
               total += number;
   }

    printf("Sum: %d\n", total);
    return 0;
}

