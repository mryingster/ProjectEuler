// -*- compile-command: "gcc -std=c99 -o problem_084 problem_084.c -Wall" -*-
// Copyright (c) 2015 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define jail 10
#define go   0

void printResults(int b[40], int m)
{


    int top[3] = {0, 1, 2};
    for (int i=0; i<40; i++)
        if (b[i] > b[top[0]])
            top[0] = i;

    for (int i=0; i<40; i++)
        if (b[i] > b[top[1]] && i != top[0])
            top[1] = i;

    for (int i=0; i<40; i++)
        if (b[i] > b[top[2]] && i != top[1] && i != top[0])
            top[2] = i;

    /*
      // Print top 3 with details
      printf("Top 3\n");
      printf("%02d: %5d (%f%%)\n", top[0], b[top[0]], b[top[0]]*100.0/m);
      printf("%02d: %5d (%f%%)\n", top[1], b[top[1]], b[top[1]]*100.0/m);
      printf("%02d: %5d (%f%%)\n", top[2], b[top[2]], b[top[2]]*100.0/m);
    */

    printf("Modal String: %2d%2d%2d\n", top[0], top[1], top[2]);

    /*
      // Print all square details
      printf("\nResults by square\n");
      for (int i=0; i<40; i++)
      printf("%02d: %5d (%f%%)\n", i, b[i], b[i]*100.0/m);
    */
}


int roll(int sides)
{
    int r = rand();
    return r % sides + 1;
}

int chance(int pos, int card)
{
    switch (card){
    case 0:
        return go;
    case 1:
        return jail;
    case 2:
        return 11;
    case 3:
        return 24;
    case 4:
        return 39;
    case 5:
        return 5;
    case 6:
    case 7:
        if (pos == 7)  return 15;
        if (pos == 22) return 25;
        if (pos == 36) return 5;
        break;
    case 8:
        if (pos == 7)  return 12;
        if (pos == 22) return 28;
        if (pos == 36) return 12;
        break;
    case 9:
        return pos-3;
    default:
        return pos;
    }
    return pos;
}

int cchest(int pos, int card)
{
    switch (card){
    case 0:
        return go;
    case 1:
        return jail;
    default:
        return pos;
    }
    return pos;
}

int main()
{
    printf("Project Euler - Problem 84\n"
           "Using 4-sided dice instead of 6-sided dice, find the 6 digit modal string representing the 3 most visited squares on the standard Monopoly board.\n\n");

    const int sides = 4;
    int pp = 0; // Player position
    int cc = 0; // Community Chest position
    int ch = 0; // Chance position
    int d  = 0; // Count of how many times doubles have been rolled.
    int m  = 0; // Number of moves
    int b[40] = {}; // Number of times each square has been visited.

    // Main loop
    while (m < 10000) //(true)
    {
        // Roll Die
        int d1 = roll(sides);
        int d2 = roll(sides);
        if (d1 == d2)
            d++;
        else
            d = 0;

        // Move player
        m++;
        if (d == 3) pp = jail;
        else
        {
            pp += d1 + d2;
            pp %= 40;
            switch (pp){
            case 7:
            case 22:
            case 36:
                ch++;
                ch %= 16;
                pp = chance(pp, ch);
                break;
            case 2:
            case 17:
            case 33:
                cc++;
                cc %= 16;
                pp = cchest(pp, cc);
                break;
            case 30:
                pp = jail;
            default:
                break;
            }
        }

        // Record turn in table
        b[pp]++;
    }

    printResults(b, m);

    return 0;
}
