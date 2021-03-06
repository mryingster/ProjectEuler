// -*- compile-command: "gcc --std=c99 -o problem_083 problem_083.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"
#include <string.h>

FILE *matrixFile;

void debugPrint(int m[80][80], int s)
{
    for (int x=0; x<s; x++)
    {
        for (int y=0; y<s; y++)
            printf("%d, ", m[x][y]);
        printf("\n");
    }
    printf("\n");
}

void printPath(bool m[80][80], int s)
{
    for (int x=0; x<=s; x++)
    {
        for (int y=0; y<=s; y++)
            if (m[x][y] == true)
                printf("*");
            else
                printf(" ");
        printf("\n");
    }
    printf("\n");
}

int min(int a, int b)
{
    if (a < b && a > 0) return a;
    return b;
}

int lowest(int a, int b, int c, int d)
{
    a = min(a, b);
    a = min(a, c);
    a = min(a, d);
    return a;
}

void copyArray(bool n[80][80], bool o[80][80])
{
    for (int x=0; x<80; x++)
        for (int y=0; y<80; y++)
            n[y][x] = o[y][x];
}

void lowestSum(int matrix[80][80], bool oldVisited[80][80], int shortest[80][80], int size, int x, int y, int value, int *solution, bool debug, int steps)
{
    bool visited[80][80] = {};
    copyArray(visited, oldVisited);
    visited[y][x] = true;

    value += matrix[y][x];

    if (value > *solution) return;

    // Arbitrary limit to speed things up. Closest step should
    // be within 10 spaces. Worked!
    if (steps++ > 10) return;

    // End Condition 1 - If we get to bottom-right element
    if (x == size && y == size)
    {
        if (debug == true)
        {
            printf("Reached end, %d\n", value);
            printPath(visited, size);
        }
        if (value < *solution)
            *solution = value;
        return;
    }

    // End Condition 2 - If we hit an element that has a best solution
    if (shortest[y][x] != 0)
    {
        value -= matrix[y][x];
        value += shortest[y][x];
        if (debug == true)
        {
            printf("Reached known value, %d\n", value);
            printPath(visited, size);
        }
        if (value < *solution)
            *solution = value;
        return;
    }

    if (x < size)
        if (visited[y][x+1] == false)
            lowestSum(matrix, visited, shortest, size, x+1, y, value, solution, debug, steps);

    if (y < size)
        if (visited[y+1][x] == false)
            lowestSum(matrix, visited, shortest, size, x, y+1, value, solution, debug, steps);

    if (y > 0)
        if (visited[y-1][x] == false)
            lowestSum(matrix, visited, shortest, size, x, y-1, value, solution, debug, steps);

    if (x > 0)
        if (visited[y][x-1] == false)
            lowestSum(matrix, visited, shortest, size, x-1, y, value, solution, debug, steps);
}

int main()
{
    printf("Project Euler - Problem 83:\n"
           "Find the minimal path sum in a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right by moving left, right, up, and down.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    int matrix[80][80]={};
    int size = sizeof(matrix[0])/sizeof(matrix[0][0]);

    // Populate table from text file
    matrixFile = fopen ("problem_083.txt", "rt");

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

    bool visited[80][80] = {};
    int shortest[80][80] = {};
    bool debug = false;

    if (debug == true)
        debugPrint(matrix, size);

    // First half - Diagonally from bottom right
    for (int m=1; m<=size; m++)
    {
        int x = size-1;
        int y = size-m;
        while (y < size)
        {
            int bestResult = 90000000;
            lowestSum(matrix, visited, shortest, size-1, x, y, 0, &bestResult, debug, 0);
            shortest[y][x] = bestResult;
            printf("%d, %d: %d %d        \r", x, y, matrix[y][x], shortest[y][x]);
            fflush(stdout);
            x--;
            y++;
        }
    }

    // Second Half - Diagonally to top left
    for (int m=1; m<=size; m++)
    {
        int x = size-m;
        int y = 0;
        while (x >= 0)
        {
            int bestResult = 90000000;
            lowestSum(matrix, visited, shortest, size-1, x, y, 0, &bestResult, debug, 0);
            shortest[y][x] = bestResult;
            printf("%d, %d: %d %d        \r", x, y, matrix[y][x], shortest[y][x]);
            fflush(stdout);
            x--;
            y++;
        }
    }

    printf("Smallest path sum: %d\n", shortest[0][0]);
    printElapsedTime(start);
    return 0;
}
