// -*- compile-command: "g++ -o problem_068 problem_068.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
#include "ceuler.h"

unsigned long long checkSolution(const int o[], const int i[])
{
    int target = o[0] + i[0] + i[1];
    unsigned long long result = 0;

    for (int p=0; p<5; p++)
    {
        int check[] = {o[p], i[p], i[(p+1)%5]};
        if (check[0] + check[1] + check[2] != target) return 0;
        for (int n=0; n<3; n++)
        {
            result *= pow(10, numberOfDigits(check[n]));
            result += check[n];
        }
    }

    return result;
}

int main()
{
    printf("Project Euler - Problem 68:\n"
           "Find the maximum concatenation for a 16 digit string for a solution to a \"magic 5-gon ring\" using the numbers 1-10?\n\n");

    //Do permutations and check answer
    unsigned long long solution = 0;
    int outer[] = {6, 7, 8, 9, 10};
    int length = sizeof(outer)/sizeof(outer[0]);
    while (std::next_permutation(outer, outer+length))
    {
        int inner[] = {1, 2, 3, 4, 5};
        //printf("%d, %d, %d, %d, %d\n", outer[0], outer[1], outer[2], outer[3], outer[4]); //DEBUG
        while (std::next_permutation(inner, inner+length))
        {
            //printf("%d, %d, %d, %d, %d\n", inner[0], inner[1], inner[2], inner[3], inner[4]); //DEBUG
            solution = checkSolution(outer, inner);
            if (solution != 0) break;
        }
        if (solution != 0) break;
    }

    printf("Solution, %llu!\n", solution);
    return 0;
}
