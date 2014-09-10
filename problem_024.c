// -*- compile-command: "gcc -o problem_024 problem_024.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    printf("Project Euler - Problem 24:\n"
           "Find the 1,000,000th lexiconic permutation of the numbers 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.\n\n");

    int array[10] = {0,1,2,3,4,5,6,7,8,8};
    int count = 0;
    int i=0, j=0;

    while (count < 1000000)
    {
        // Increment number
        array[9]++;
        for (i=9; i>0; i--)
        {
            if (array[i]>9)
            {
                array[i]-=10;
                array[i-1]++;
            }
        }

        // Check if numbers are unique
        int invalid = 0;
        for (i=0; i<10; i++)
        {
            for (j=i+1; j<10; j++)
            {
                if (array[i] == array[j])
                {
                    invalid = 1;
                    break;
                }
            }
            if (invalid == 1)
                break;
        }

        // If numbers are unique, increment permutation count
        if (invalid == 0)
        {
            count++;
            /*
            // DEBUG print found permutations
            for (i=0; i<10; i++)
            printf("%d", array[i]);
            printf("\n");
            */
        }
    }

    printf("%dth permutation: %d%d%d%d%d%d%d%d%d%d\n", count,
           array[0], array[1], array[2], array[3], array[4],
           array[5], array[6], array[7], array[8], array[9]);

    return 0;
}
