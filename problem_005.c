// -*- compile-command: "gcc -o problem_005 problem_005.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    int i, j, candidate;

    printf("Project Euler - Problem 5:\n"
           "What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n\n");

    for (i=1000 ; i<699000000 ; i=i+20)
    {
        candidate=i;
        for (j=1 ; j<21 ; j++)
	{
            if (i % j)
	    {
                candidate=0;
                //printf("%i Not divisible by %i\n", i, j);
                break;
	    }
	}
        if (candidate != 0)
            break;
    }

  printf("Smallest number: \033[1m%i\033[0m\n", candidate);

  return 0;
}

