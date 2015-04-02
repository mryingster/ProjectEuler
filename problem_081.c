// -*- compile-command: "gcc -o problem_081 problem_081.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *matrixFile;

int main(){
    printf("Project Euler - Problem 81:\n"
           "Find the minimal path sum in a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right by only moving right and down.\n\n");

    int matrix[80][80]={};
    int x = 0, y = 0;

    //Populate table from text file
    matrixFile = fopen ("problem_081.txt", "rt");

    char ch;
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

    //Go through entire grid
    for (x=0; x<80; x++)
    {
        for (y=0; y<80; y++)
	{
            //Find best move for each position
            if (x==0 && y==0) continue; //Skip first cell

            //If on left or top edge, make obligatory move
            if (x==0)
                matrix[x][y] += matrix[x][y-1];
            else if (y==0)
                matrix[x][y] += matrix[x-1][y];

            //Find best move, and make it, replace element value
            else if (matrix[x-1][y] < matrix[x][y-1])
                matrix[x][y] += matrix[x-1][y];
            else
                matrix[x][y] += matrix[x][y-1];
	}
    }

    printf("Smallest path sum: %d\n", matrix[79][79]);
    return 0;
}
