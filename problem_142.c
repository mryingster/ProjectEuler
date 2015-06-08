// -*- compile-command: "gcc -std=c99 -o problem_142 problem_142.c -Wall ceuler.c -lm -O3" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <math.h>
#include "ceuler.h"

bool isperfect(int input){
    int i=sqrt(input);
    if (i*i == input)
        return true;
    return false;
}

int main(){
    printf("Project Euler - Problem 142:\n"
           "Find the smallest x + y + z with integers x > y > z > 0 such that x + y, x − y, x + z, x − z, y + z, y − z are all perfect squares.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    bool debug = false;
    int sum = 0;

    for (int x=5; sum==0; x++)
    {
        for (int y=4; y<x; y+=2)
        {
            if (isperfect(x + y) == false) continue;
            if (isperfect(x - y) == false) continue;
            for (int z=2; z<y; z+=2)
            {
                if (isperfect(x + z) == false) continue;
                if (isperfect(x - z) == false) continue;
                if (isperfect(y + z) == false) continue;
                if (isperfect(y - z) == false) continue;

                // If we are this far, it's an elligible number!
                sum = x+y+z;
                if (debug == true)
                    printf("%d, %d, %d, sum:%d\n", x, y, z, sum);

                break;
            }
            if (sum != 0) break;
        }
        if (sum != 0) break;
    }

    printf("Sum: %d\n", sum);
    printElapsedTime(start);

    return 0;
}
