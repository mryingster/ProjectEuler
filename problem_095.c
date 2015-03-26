// -*- compile-command: "gcc -std=c99 -o problem_095 problem_095.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>

typedef struct divisors divisors;
struct divisors{
    int sum;
    int len;
};

int main()
{
    printf("Project Euler - Problem 95:\n"
           "Find the smallest member of the longest amicable chain with no element exceeding one million.\n\n");

    static divisors divisors[1000000];
    int searchLen = sizeof(divisors)/sizeof(divisors[0]);

    // Populate our divisor table
    for (int i=1; i<searchLen; i++)
        for (int j=i+i; j<searchLen; j+=i)
            divisors[j].sum += i;

    // Determine Chain Lengths
    int longest = 0, smallest = 0;
    for (int i = 0; i < searchLen; i++)
    {
        int index = i, length = 0;

        while (1)
        {
            // Valid chains
            if (divisors[index].sum == i)
            {
                divisors[i].len = length;
                if (length > longest)
                {
                    longest = length;
                    smallest = i;
                }
                break;
            }

            // Invalid chains
            if (divisors[index].len != 0 || length > 100 || divisors[index].sum > searchLen)
            {
                divisors[i].len = -1;
                break;
            }

            index = divisors[index].sum;
            length++;
        }
    }

    printf("Longest chain length: %d\n", longest);
    printf("Smallest chain element: %d\n", smallest);

    return 0;
}
