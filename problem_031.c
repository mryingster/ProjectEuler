// -*- compile-command: "gcc -o problem_031 problem_031.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    printf("Project Euler - Problem 30:\n"
           "How many different ways can 2 pounds be made using any number of coins?\n\n");

    int counter[8] = {0,0,0,0,0,0,0,0};
    int sum = 0;
    int count = 0;
    int n = 0;

    while (counter[6] <= 200)
    {
        sum=0;
        counter[0]=counter[0]+1;
        if (counter[0] > 200 - counter[1] - counter[2] - counter[3] - counter[4] - counter[5] - counter[6] - counter[7])
        {
            counter[0] = 0;
            counter[1] += 2;
        }
        if (counter[1] > 200 - counter[2] - counter[3] - counter[4] - counter[5] - counter[6] - counter[7])
        {
            counter[1] = 0;
            counter[2] += 10;
        }
        if (counter[2] > 200 - counter[3] - counter[4] - counter[5] - counter[6] - counter[7])
        {
            counter[2] = 0;
            counter[3] += 5;
        }
        if (counter[3] > 200 - counter[4] - counter[5] - counter[6] - counter[7])
        {
            counter[3] = 0;
            counter[4] += 20;
        }
        if (counter[4] > 200 - counter[5] - counter[6] - counter[7])
        {
            counter[4] = 0;
            counter[5] += 50;
        }
        if (counter[5] > 200 - counter[6] - counter[7])
        {
            counter[5] = 0;
            counter[6] += 100;
        }
        if (counter[6] > 200 - counter[7])
        {
            counter[6] = 0;
            counter[7] += 200;
        }
        for (n=0 ; n<8 ; n++)
            sum += counter[n];
        if ( sum == 200)
        {
            count++;
            if ( counter[7] == 200 ) break;
        }
    }

    printf("Ways: %i\n", count);

    return 0;
}
