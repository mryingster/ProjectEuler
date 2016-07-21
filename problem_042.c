// -*- compile-command: "gcc -o problem_042 problem_042.c ceuler.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ceuler.h"

FILE *wordFile;
const int maxWordSize = 80;

int main()
{
    printf("Project Euler - Problem 42:\n"
           "In a list of two-thousand common English words, how many are triangle words?\n\n");

    char words[2000][maxWordSize];
    int wordIndex = 0;
    int charIndex = 0;
    int ch;
    int total = 0;

    wordFile = fopen ("problem_042.txt", "rt");

    // Read in words to array
    while((ch = fgetc(wordFile)))
    {
        if (ch == EOF) break;

        if (ch == '"') continue;

        if (ch == ',')
        {
            wordIndex++;
            charIndex = 0;
            continue;
        }

        words[wordIndex][charIndex] = ch;
        charIndex++;
    }

    fclose(wordFile);

    //Calculate Tirangle Numbers
    int triIndex;
    int triangles[100]={0};
    for (triIndex=0 ; triIndex<100 ; triIndex++)
        triangles[triIndex] = (triIndex+1) * triIndex/2;

    // Get word score, check if triangle
    int wordMax = wordIndex;
    for(wordIndex=0; wordIndex <= wordMax; wordIndex++)
    {
        int score = wordScore(words[wordIndex], maxWordSize);
        for (triIndex=0 ; triIndex<100 ; triIndex++)
        {
            if (score == triangles[triIndex])
            {
                total++;
                break;
            }
        }
    }

    printf("Triangle words: %d\n", total);
    return 0;
}
