// -*- compile-command: "gcc -std=c99 -o problem_109 problem_109.c -Wall ceuler.c -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 109:\n"
           "In a standard game of darts, how many distinct ways can a player check out with a score less than 100?\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int scores[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,25,  // Single
                    3, 6, 9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,     // Triple
                    2, 4, 6, 8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,50}; // Double
    int len = sizeof(scores)/sizeof(int);
    const int doubles = 41; // Doubles start at index 41
    int count = 0;
    bool debug = false;

    for (int score=2; score < 100; score++)
    {
        // Throw 1
        for (int a=0; a<len; a++)
        {
            int total = scores[a];
            if (total > score) continue;
            if (total == score && a >= doubles)
            {
                count++;
                if (debug == true)
                    printf("%d (%d)\n", total, scores[a]);
            }

            // Throw 2
            for (int b=0; b<len; b++)
            {
                total = scores[a] + scores[b];
                if (total < score && b < a) continue;
                if (total > score) continue;
                if (total == score && b >= doubles)
                {
                    count++;
                    if (debug == true)
                        printf("%d (%d, %d)\n", total, scores[a], scores[b]);
                }

                // Throw 3
                for (int c=doubles; c<len; c++)
                {
                    total = scores[a] + scores[b] + scores[c];
                    if (total != score) continue;
                    count++;
                    if (debug == true)
                        printf("%d (%d, %d, %d)\n", total, scores[a], scores[b], scores[c]);
                }
            }
        }
    }

    printf("%d ways\n", count);
    printElapsedTime(start);

    return 0;
}
