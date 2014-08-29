// -*- compile-command: "gcc -o problem_001 problem_001.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    int i, total = 0;

    printf("Project Euler - Problem 1:\n"
           "Find the sum of all the multiples of 3 or 5 below 1000.\n\n");

   for (i=0 ; i<1000 ; i++)
   {
       if ( i % 3 )
           if ( i % 5 )
               printf("");
           else
               total=total+i;
       else
           total=total+i;
    }

    printf("Sum: \033[1m%i\033[0m\n", total);
    return 0;
}

