// -*- compile-command: "gcc -std=c99 -o problem_071 problem_071.c ceuler.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

typedef struct fraction fraction;
struct fraction{
    int numerator;
    int denominator;
    double value;
};

void assign(fraction *f, const int n, const int d)
{
    f->numerator = n;
    f->denominator = d;
    f->value = (double)n/(double)d;
}

int main()
{
    printf("Project Euler - Problem 71:\n"
           "By listing the set of reduced proper fractions for d <= 1,000,000 in ascending order of size, find the numerator of the fraction immediately to the left of 3/7.\n\n");

    fraction target;
    assign(&target, 3, 7);

    fraction left;
    assign(&left, 2, 7);

    for (int denominator = 7 ; denominator <= 1000000 ; denominator++)
    {
        for (int numerator = denominator/7*3 ; numerator <= denominator; numerator ++)
        {
            fraction current;
            assign(&current, numerator, denominator);

            if(current.value >= target.value) break;
            if(current.value >= left.value)
                assign(&left, current.numerator, current.denominator);
        }
    }

    printf("Fraction left of 3/7: %d/%d (%F)\n", left.numerator, left.denominator, left.value);
    return 0;
}
