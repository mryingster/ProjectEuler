// -*- compile-command: "gcc -std=c99 -o problem_072 problem_072.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main(){
    printf("Project Euler - Problem 72:\n"
           "How many elements would be contained in the set of reduced proper fractions for d <= 1,000,000?\n\n");

    //Maximum value to try
    int MaxValue=1000000+1;

    unsigned long long count=0;
    int phi[1000000+1];

    //Give each element initial value
    for (int i=0 ; i<MaxValue ; i++)
        phi[i] = i;

    //Perform eulers totient function
    for (int n=2 ; n<=MaxValue ; n++)
        if (phi[n]==n)
            for (int k=n;k<MaxValue;k=k+n)
                phi[k] *= (n - 1.0) / n;

    //Print/tabulate results
    for (int i=0 ; i<MaxValue ; i++)
    {
        //printf("%i, ",phi[i]);
        count += phi[i];
    }
    //printf("\n");

    printf("Number of unique fractions: %llu\n", count-1);
    return 0;
}
