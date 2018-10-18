// -*- compile-command: "gcc -std=c99 -o problem_126 problem_126.c ceuler.c -Wall -lm -O3" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "ceuler.h"


int cubesToCover(int x, int y, int z, int n) {
    return 2 * (x*y + y*z + x*z) + 4 * (x + y + z + n - 2) * (n - 1);
}

int main() {
    printf("Project Euler - Problem 126:\n"
           "We shall define C(n) to represent the number of cuboids that contain n cubes in one of its layers. Find the least value of n for which C(n) = 1000.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    bool debug = false;
    int limit = 5000;
    int results[25000] = {};
    int arraysize = sizeof(results)/sizeof(results[0]);

    for (int z=1; z<limit; z++) {
        if (debug == true)
            printf("%d/%d\n", z, limit);
        for (int y=z; y<limit; y++) {
            for (int x=y; x<limit; x++) {
                for (int n=1; n<limit; n++) {
                    int cubes = cubesToCover(x,y,z,n);
                    if (cubes >= arraysize)
                        break;
                    results[cubes] += 1;
                }
            }
        }
    }

    for (int i=0; i<arraysize; i++) {
        if (results[i] == 1000) {
            printf("%d\n", i);
            break;
        }
    }

    printElapsedTime(start);

    return 0;
}
