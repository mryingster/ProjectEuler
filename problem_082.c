// -*- compile-command: "gcc -std=c99 -o problem_082 problem_082.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <string.h>
#include "ceuler.h"

FILE *matrixFile;

void debugPrint(int m[80][80], int s)
{
    for (int x=0; x<s; x++)
    {
        printf("Row %2d: ", x);
        for (int y=0; y<s; y++)
            printf("%6d, ", m[x][y]);
        printf("\n");
    }
    printf("\n");
}

void computeColumn(int matrix[80][80], int size, int x, bool debug)
{
    int newCol[size];

    // Prime newCol with value + value to right
    for (int y=0; y<size; y++)
        newCol[y] = matrix[y][x] + matrix[y][x+1];

    // Get value up
    for (int y=1; y<size; y++)
    {
        int upValue = newCol[y-1] + matrix[y][x];
        if (upValue < newCol[y]) newCol[y] = upValue;
    }

    // Get value down
    for (int y=size-2; y>=0; y--)
    {
        int downValue = newCol[y+1] + matrix[y][x];
        if (downValue < newCol[y]) newCol[y] = downValue;
    }

    // Copy values back to matrix
    for (int y=0; y<size; y++)
        matrix[y][x] = newCol[y];
}

int main(){
    printf("Project Euler - Problem 82:\n"
           "Find the minimal path sum in a 31K text file containing a 80 by 80 matrix, from the top left column to right column.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int matrix[80][80]={};
    int size = sizeof(matrix[0])/sizeof(matrix[0][0]);
    bool debug = false;

    //Populate table from text file
    matrixFile = fopen ("problem_082.txt", "rt");

    char ch;
    int x = 0, y = 0;
    while((ch = fgetc(matrixFile)))
    {
        if (ch == EOF) break;
        if (ch == ',')
        {
            x++;
            continue;
        }

        if (ch == '\n')
        {
            x = 0;
            y++;
            continue;
        }

        matrix[y][x] *= 10;
        matrix[y][x] += ch - '0';
    }

    fclose(matrixFile);

    // Solve optimal path one column at a time
    for (int x=size-2; x>=0; x--)
        computeColumn(matrix, size, x, debug);

    // Print completed matrix
    if (debug == true) debugPrint(matrix, size);

    // Find smallest value in left column
    int smallestAnswer = matrix[0][0];
    for (int y=1; y<size; y++)
        if (matrix[y][0] < smallestAnswer)
            smallestAnswer = matrix[y][0];

    printf("Smallest path sum: %d\n", smallestAnswer);
    printElapsedTime(start);
    return 0;
}
