// -*- compile-command: "gcc -o problem_022 problem_022.c ceuler.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ceuler.h"

FILE *nameFile;
const int maxNameSize = 80;

int compare(const void *a, const void *b)
{
    //printf("%s %s\n", a, b); // DEBUG
    return strcmp(a, b);
}

int main()
{
    printf("Project Euler - Problem 22:\n"
           "Sort 5000 names and calculate the sum of their name scores.\n\n");

    char names[6000][maxNameSize] = {};
    int nameIndex = 0;
    int charIndex = 0;
    int ch;
    int score = 0;

    nameFile = fopen ("problem_022.txt", "rt");

    // Read in names to array
    while((ch = fgetc(nameFile)))
    {
        if (ch == EOF) break;

        if (ch == '"') continue;

        if (ch == ',')
        {
            nameIndex++;
            charIndex = 0;
            continue;
        }

        names[nameIndex][charIndex] = ch;
        charIndex++;
    }

    fclose(nameFile);

    // Sort array
    qsort(names, nameIndex+1, sizeof(names[0]), compare);

    // Score names
    int index = 0;
    for(index=0; index <= nameIndex; index++)
        score += (index + 1) * wordScore(names[index], maxNameSize);

    printf("Total name score: %d\n", score);
    return 0;
}
