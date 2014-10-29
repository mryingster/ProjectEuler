// -*- compile-command: "gcc -o problem_052 problem_052.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ceuler.h"

int main()
{
    printf("Project Euler - Problem 52:\n"
           "Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.\n\n");

    int number = 1;

    while (number++ < 1000000)
    {
        int checkSig = numSignature(number);
        if (checkSig != numSignature(number * 2)) continue;
        if (checkSig != numSignature(number * 3)) continue;
        if (checkSig != numSignature(number * 4)) continue;
        if (checkSig != numSignature(number * 5)) continue;
        if (checkSig != numSignature(number * 6)) continue;
        break;
    }

    printf("Smallest Number: %d\n", number);
    return 0;
}
