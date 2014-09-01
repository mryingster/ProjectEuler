// -*- compile-command: "gcc -o problem_009 problem_009.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;
    int product = 0;

    printf("Project Euler - Problem 9:\n"
           "There exists exactly one Pythagorean triplet for which a + b + c = 1000.\n"
           "Find the product abc.\n\n");

    for (a=1 ; a<1000 ; a++)
    {
        for (b=a ; b<1000 ; b++)
        {
            for (c=b ; c<1000 ; c++)
            {
                if (a*a + b*b == c*c)
                    if (a + b + c == 1000)
                    {
                        //printf("Found Match. %i %i %i %i\n", a, b, c, a*b*c);
                        product=a*b*c;
                        break;
                    }
            }
            if (product != 0)
                break;
        }
        if (product != 0)
            break;
    }

    printf("Product: \033[1m%i\033[0m\n", a * b * c);

    return 0;
}
