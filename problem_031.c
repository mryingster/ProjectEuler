// -*- compile-command: "gcc -o problem_031 problem_031.c -Wall -O3" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int addCounter(int *counter, int start, int stop)
{
    int sum = 0;
    int i;

    for (i=start; i<=stop; i++)
        sum += counter[i];

    return sum;
}

int main()
{
    printf("Project Euler - Problem 30:\n"
           "How many different ways can 2 pounds be made using any number of coins?\n\n");

    int counter[8] = {0,0,0,0,0,0,0,0};
    int count = 0;

    while (counter[6] <= 200)
    {
        counter[0]=counter[0]+1;
        if (counter[0] > 200 - addCounter(counter, 1,7))
        {
            counter[0] = 0;
            counter[1] += 2;
        }
        if (counter[1] > 200 - addCounter(counter, 2,7))
        {
            counter[1] = 0;
            counter[2] += 10;
        }
        if (counter[2] > 200 - addCounter(counter, 3,7))
        {
            counter[2] = 0;
            counter[3] += 5;
        }
        if (counter[3] > 200 - addCounter(counter, 4,7))
        {
            counter[3] = 0;
            counter[4] += 20;
        }
        if (counter[4] > 200 - addCounter(counter, 5,7))
        {
            counter[4] = 0;
            counter[5] += 50;
        }
        if (counter[5] > 200 - addCounter(counter, 6,7))
        {
            counter[5] = 0;
            counter[6] += 100;
        }
        if (counter[6] > 200 - counter[7])
        {
            counter[6] = 0;
            counter[7] += 200;
        }
        if ( addCounter(counter, 0,7) == 200)
        {
            count++;
            if ( counter[7] == 200 ) break;
        }
    }

    printf("Ways: %d\n", count);

    return 0;
}
