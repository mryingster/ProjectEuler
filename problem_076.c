// -*- compile-command: "gcc -std=c99 -o problem_076 problem_076.c -Wall" -O3 -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>

void debugPrint(int a[], int len)
{
    for (int i=0; i<len; i++)
        printf("%i,", a[i]);
    printf("0\n");
}

int main()
{
    printf("Problem 76\n"
           "How many different ways can one hundred be written as a sum of at least two positive integers?\n\n");

    const int target = 100;
    int array[101] = {};
    unsigned long long count = 0;

    for (int i=0; i<target; i++)
        array[i] = 1;

    while (true)
    {
        count++;
        bool didSomething = false;

        //debugPrint(array, target);

        // Array manipulation
        for (int i=target; i>0; i--)
	{
            if (array[i] == 0) // skip if it's a 0
                continue;

            if (array[i-1] > array[i] && array[i+1] != 0) // left is bigger, right number != 0
	    {
                array[i]++; // increment
                didSomething = true;

                // need to add, fill in to right with 1's until == target
                int sum = 0;
                for (int j=0; j<=i; j++)
                    sum += array[j];

                for (int j=i+1; j<100; j++)
		{
                    sum++;
                    if (sum <= target)
                        array[j] = 1;
                    else
                        array[j] = 0;
		}
                break;
	    }
	}

        if (didSomething == false)
	{
            // if no good moves found, go back to left-most smallest number and increment, fill in with 1's
            int sum = 0;
            array[0]++;
            sum = array[0];
            for (int j=1; j<100; j++)
            {
                sum++;
                if (sum <= target)
                    array[j] = 1;
                else
                    array[j] = 0;
            }
	}

        // Finished if we've incremented to the target number!
        if (array[0] == target)
            break;
    }

    printf("Total: %llu\n", count);
    return 0;
} 

/*
Method

Have array with 1's eg (1,1,1,1,1,0)
Starting at element 0, if number to the right is 1, add to current element, shift numbers down eg (2,1,1,1,0,0)
Repeat until number at right is 0 eg (2,2,1,0,0,0)
Move to begining and increment number, fill rest out with 1's until adds up to number eg (3,1,1,0,0
 */
