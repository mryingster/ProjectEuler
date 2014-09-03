// -*- compile-command: "gcc -o problem_012 problem_012.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    int i, j, m, n, x, y;
    int largest = 0, candidate = 0;
    i=j=m=n=x=y=0;

    printf("Project Euler - Problem 12:\n"
           "What is the value of the first triangle number to have over five hundred divisors?\n\n");


    for (i=1 ; i<1000000 ; i++)
    {
        m=0;
        for (n=1 ; n<i; n++)
	{
            m=m+n;
	}
        j=m;
        y=0;
        for (x=1 ; x<j ; x++)
	{
            if (j % x)
                printf("");
            //printf("not divisible by %i\n", x);
            else
	    {
                //printf("divisible by %i\n", x);
                y=y+1;
	    }
	}
        //printf("%i : %i : %i\n", i, j, y);
        if (y>500)
            break;
    }

    printf("Triangle Value: \033[1m%i\033[0m, Nth Triangle Number: %i, Divisors: %i\n", m, i, y);
    return 0;
}
