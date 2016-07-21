// -*- compile-command: "gcc -o problem_067 problem_067.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *triangleFile;
const int maxTriangleSize = 200;

int main()
{
    printf("Project Euler - Problem 67:\n"
           "Find the maximum total from top to bottom in a triangle with one-hundred rows.\n\n");

    int triangle[maxTriangleSize][maxTriangleSize];

    // Read in triangle to array
    triangleFile = fopen ("problem_067.txt", "rt");
    int row = 0, col = 0;
    char ch;
    while((ch = fgetc(triangleFile)))
    {
        if (ch == EOF) break;

        if (ch == ' ')
        {
            col++;
            continue;
        }

        if (ch == '\n')
        {
            col = 0;
            row++;
            continue;
        }

        triangle[row][col] *= 10;
        triangle[row][col] += ch - '0';
    }

    fclose(triangleFile);
    int size = row;

    // Find Max Path
    for (row = size-1 ; row >= 0 ; row--)
    {
        for (col = 0 ; col < size ; col++)
        {
            if (triangle[row+1][col] >= triangle[row+1][col+1])
                triangle[row][col] = triangle[row][col] + triangle[row+1][col];
            else
                triangle[row][col] = triangle[row][col] + triangle[row+1][col+1];
        }
    }

    printf("Greatest sum: %d\n", triangle[0][0]);
    return 0;
}
