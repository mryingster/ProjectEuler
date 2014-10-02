// -*- compile-command: "gcc -o problem_009 problem_009.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    const int target = 1000;
    int product = 0;
    int a, b, c;

    printf("Project Euler - Problem 9:\n"
           "There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.\n\n");

    for (a=1 ; a<target/2 ; a++)
    {
        for (b=a ; b<target/2 ; b++)
        {
            for (c=b ; c<target ; c++)
            {
                if (a*a + b*b == c*c && a + b + c == target)
                {
                    //printf("Found Match. %d %d %d %i\n", a, b, c, a*b*c); //DEBUG
                    product = a*b*c;
                    break;
                }
            }
            if (product != 0)
                break;
        }
        if (product != 0)
            break;
    }

    printf("Product: %d\n", product);

    return 0;
}
