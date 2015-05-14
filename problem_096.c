// -*- compile-command: "gcc -std=c99 -o problem_096 problem_096.c -Wall -lm" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

FILE *nameFile;

typedef struct puzzle puzzle;

struct puzzle
{
    int cell[9][9][10];
};

bool isSolved(puzzle g)
{
    for (int x=0; x<9; x++)
        for (int y=0; y<9; y++)
            if (g.cell[x][y][0] == 0)
                return false;
    return true;
}

void printPuzzle(puzzle g)
{
    printf("\n");
    for (int i=0; i<9; i++)
    {
        printf(" %d %d %d | %d %d %d | %d %d %d \n",
               g.cell[i][0][0], g.cell[i][1][0], g.cell[i][2][0],
               g.cell[i][3][0], g.cell[i][4][0], g.cell[i][5][0],
               g.cell[i][6][0], g.cell[i][7][0], g.cell[i][8][0]);
        if ((i + 1) % 3 == 0 && i < 7)
            printf("-------+-------+-------\n");
    }
    printf("\n");
}

void printPuzzleOptions(puzzle g)
{
    printf("\n");
    for (int x=0; x<9; x++)
    {
        for (int y=0; y<9; y++)
        {
            if (g.cell[x][y][0] > 0)
                printf("%d ", g.cell[x][y][0]);
            else
            {
                printf("[");
                for (int i=1; i<10; i++)
                    if (g.cell[x][y][i] == true)
                        printf("%d, ", i);
                printf("]");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int isSingleCandidate(puzzle *g, int x, int y)
{
    int count = 0;
    int candidate = 0;
    for (int i=1; i<10; i++)
        if (g->cell[x][y][i] == false)
            count++;
        else
            candidate = i;

    if (count == 8)
        return candidate;
    return 0;
}

void eliminateNumberInLine(puzzle *g, int x, int y)
{
    for (int i=0; i<9; i++)
    {
        if (g->cell[i][y][0] > 0)                     // Search in row. If not blank (0)...
            g->cell[x][y][g->cell[i][y][0]] = false;  // Mark candidate for that number as false
        if (g->cell[x][i][0] > 0)                     // Search in col. If not blank (0)...
            g->cell[x][y][g->cell[x][i][0]] = false;  // Mark candidate for that number as false
    }
}

void eliminateNumberInBox(puzzle *g, int x, int y)
{
    int row = ceil(x/3)*3;                        // Confine to 3x3 square
    int col = ceil(y/3)*3;                        // Confine to 3x3 square

    for (int i=row; i<row+3; i++)
        for (int n=col; n<col+3; n++)                    // Search square
            if (g->cell[i][n][0] > 0)                    // for non-zero values
                g->cell[x][y][g->cell[i][n][0]] = false; // Mark false
}

void crossCheckBoxCandidates(puzzle *g, int x, int y)
{
    int row = ceil(x/3)*3;
    int col = ceil(y/3)*3;

    for (int j=1; j<10; j++)                    // For each candidate for x, y
    {
        if (g->cell[x][y][j] == 0) continue;    // Skip non-candidates
        bool uniqueCandidate = true;
        for (int i=row; i<row+3; i++)           // Check if candidates exist in other elements
            for (int n=col; n<col+3; n++)
            {
                if (i==x && n==y) continue;     // Don't check self...
                if (g->cell[i][n][j] != false)  // If candidate exists in other cells
                    uniqueCandidate = false;    // Mark as not unique solution
            }

        if (uniqueCandidate == true)            // If solution is unique...
        {
            for (int d=1; d<10; d++)
                if (d != j)
                    g->cell[x][y][d] = 0;       // Zero out other candidates from x, y
            return;
        }
    }
}

void crossCheckLineCandidates(puzzle *g, int x, int y)
{
    for (int j=1; j<10; j++)                     // For each candidate for x, y
    {
        if (g->cell[x][y][j] == false) continue; // Skip non-candidates

        bool uniqueCandidate = true;
        for (int i=0; i<9; i++)                  // Check if candidates exist in row elements
        {
            if (i == x) continue;                // But don't check self...
            if (g->cell[i][y][j] != 0)              // If candidate is not unique
                uniqueCandidate = false;         // Mark as not unique
        }

        if (uniqueCandidate == true)             // If solution is unique...
        {
            for (int d=0; d<9; d++)
                if (d != j)
                    g->cell[x][y][d] = false;    // Zero out other candidates from x, y
            return;
        }

        uniqueCandidate = true;
        for (int i=0; i<9; i++)                  // Check if candidates exist in col elements
        {
            if (i == y) continue;                // Don't check self...
            if (g->cell[x][i][j] != 0)              // If candidate is not unique
                uniqueCandidate = false;         // Mark as not unique
        }

        if (uniqueCandidate == true)             // If solution is unique...
        {
            for (int d=1; d<10; d++)
                if (d != j)
                    g->cell[x][y][d] = false;    // Zero out other candidates from x, y
            return;
        }
    }
}

void solveGrid(puzzle *g)
{
    bool changed = true;
    while (changed == true)
    {
        changed = false;
        for (int x=0; x<9; x++)                                   // Get candidates & easy solutions
            for (int y=0; y<9; y++)
            {
                if (g->cell[x][y][0] > 0) continue;               // Skip non-empty cells
                for (int j=1; j<10; j++) g->cell[x][y][j] = true; // Populate candidate values
                eliminateNumberInLine(g, x, y);                   // Eliminate candidates from row & col
                eliminateNumberInBox(g, x, y);                    // Eliminate candidates from box
                int newValue = isSingleCandidate(g, x, y);        // See if single candidate remains
                if (newValue != 0)
                {
                    g->cell[x][y][0] = newValue;                  // Apply result to cell
                    changed = true;                               // Keep track that change was made
                }
        }
        if (changed == true) continue;

        for (int x=0; x<9; x++)                                   // Use candidates to find harder solutions
            for (int y=0; y<9; y++)
            {
                if (g->cell[x][y][0] > 0) continue;               // Skip non-empty cells
                crossCheckLineCandidates(g, x, y);                // Check for elements that can only work in current cell
                crossCheckBoxCandidates(g, x, y);                 // Check for elements that can only work in current cell
                int newValue = isSingleCandidate(g, x, y);        // See if single candidate remains
                if (newValue != 0)
                {
                    g->cell[x][y][0] = newValue;                  // Apply result to cell
                    changed = true;                               // Keep track that change was made
                }
            }
    }
}

void copyPuzzle(puzzle g, puzzle *t)
{
    for (int x=0; x<9; x++)
        for (int y=0; y<9; y++)
            for (int j=0; j<10; j++)
                t->cell[x][y][j] = g.cell[x][y][j];
}

void guessSolution(puzzle *g, int level)
{
    if (level > 2) return;                              // Don't allow recursion beyond 2 to happen.
    if (isSolved(*g)) return;                           // Don't recurse if solved

    for (int x=0; x<9; x++)
        for (int y=0; y<9; y++)
            if (g->cell[x][y][0] == 0)                  // Look for cells that aren't solved.
            {
                bool movePossible = false;              // Keep track of possible moves
                for (int j=1; j<10; j++)
                {
                    puzzle t;
                    copyPuzzle(*g, &t);                 // Copy puzzle so we keep original intact
                    if (t.cell[x][y][j] == true)        // See if j is a candidate number
                    {
                        movePossible = true;            // We have a valid move to try
                        t.cell[x][y][0] = j;            // Set cell to candidate value
                        solveGrid(&t);                  // Try solving grid
                        if (isSolved(t))                // If solved,
                        {
                            copyPuzzle(t, g);           // Copy solved puzzle back to master
                            return;                     // and return!
                        }
                        else
                        {
                            guessSolution(&t, level+1); // Recurse back if not yet solved
                            if (isSolved(t))            // If that did the trick
                            {
                                copyPuzzle(t, g);       // Copy back to master
                                return;                 // And return!
                            }
                        }
                    }
                }
                if (movePossible == false)              // If no valid moves are found
                    return;                             // Dead end. Return...
            }
}

int main()
{
    printf("Project Euler - Problem 96:\n"
           "By solving fifty Sudoku puzzles, find the sum of the 3-digit numbers found in the top left corner of each solution grid.\n\n");

    puzzle sudoku[50]; // Struct for all 50 Sudoku grids and candidates
    bool verbose = false;

    // Read in game grids
    nameFile = fopen ("problem_096.txt", "rt");
    int grid = -1, row = -1, col = 0, ch;
    bool skip = false;
    while((ch = fgetc(nameFile)))
    {
        if (ch == EOF) break;
        if (ch == 'G')
        {
            skip = true;
            row = -1;
            grid++;
        }
        if (ch == '\n')
        {
            row++;
            col = 0;
            skip = false;
            continue;
        }
        if (skip == true) continue;

        ch -= '0'; // Convert from ASCII to DEC
        sudoku[grid].cell[row][col][0] = ch;
        col++;
    }

    fclose(nameFile);

    // Solve grid by grid
    int numSolved = 0;
    for (int i=0; i<50; i++)
    {
        if (verbose == true) printf("Grid: %d\n", i+1);

        // Simple deduction first
        solveGrid(&sudoku[i]);

        if (isSolved(sudoku[i]))
        {
            numSolved++;
            if (verbose == true) printPuzzle(sudoku[i]);
            continue;
        }

        // Cycle through options looking for answers
        guessSolution(&sudoku[i], 1);

        if (isSolved(sudoku[i]))
        {
            numSolved++;
            if (verbose == true) printPuzzle(sudoku[i]);
            continue;
        }

        if (verbose == true) printf("Unsolved...\n");
        if (verbose == true) printPuzzle(sudoku[i]);
    }

    // Add up top, left-most numbers
    int sum = 0;
    for (int i=0; i<50; i++)
    {
        int num = sudoku[i].cell[0][0][0]*100;
        num +=    sudoku[i].cell[0][1][0] * 10;
        num +=    sudoku[i].cell[0][2][0];
        sum += num;
        if (verbose == true) printf("Grid %2d: %d\n", i+1, num);
    }

    printf("Solved %d out of %d.\n", numSolved, 50);
    printf("Sum: %d\n", sum);

    return 0;
}
