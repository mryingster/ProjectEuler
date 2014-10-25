// -*- compile-command: "gcc -o problem_053 problem_053.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>

bool qualifies(int n, int r)
{
    const int limit = 1000000;
    int nr = n-r;
    unsigned long long answer = 1;

    //printf("%d %d: ", n, r); //DEBUG

    while (n > r)
    {
        answer *= n;
        while ( nr > 1 && (answer % nr == 0 || answer > limit)) //% nr == 0 )
        {
            answer /= nr;
            nr--;
        }

        if (nr <= 1 && answer > limit) return true;

        n--;
    }

    //printf(" (%d) %llu\n", nr, answer); //DEBUG

    return false;
}

int main()
{
    printf("Project Euler - Problem 53:\n"
           "How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?\n\n");

    int total=0, r, n;

    for (n=23 ; n<101; n++) //101
        for (r=1 ; r<n; r++)
        {
            if (qualifies(n, r) == true)
                total++;
        }
    printf("Total: %d\n", total);
    return 0;
}
