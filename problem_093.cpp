// -*- compile-command: "g++ -std=c++0x -o problem_093 problem_093.cpp ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
#include <string>
#include <iostream>
#include "ceuler.h"

// Perform operation based on integer
double op(const double a, const double b, const int o)
{
    switch (o)
    {
    case 0: return a + b;
    case 1: return a - b;
    case 2: return a * b;
    case 3: return a / b;
    }
    return 1;
}

int arith(const int a, const int b, const int c, const int d)
{
    int  i[4] = {a, b, c, d};         // Integers
    int  il = sizeof(i)/sizeof(i[0]); // Intergers length

    bool h[3024] = {};                // History - Max is 9*8*7*6
    int  hl = sizeof(h)/sizeof(h[0]); // History length

    // Permute through integer combinations
    for (int n=0; n<24; n++)
    {
        double answer = 0;
        // Try all operation combinations
        for (int a = 0; a < 4; a++)
            for (int b = 0; b < 4; b++)
                for (int c = 0; c < 4; c++)
                {
                    // a + b + c + d
                    answer = op(op(op(i[0],i[1],a),i[2],b),i[3],c);
                    if (answer > 0 && fmod(answer, 1) == 0)
                        h[(int)answer] = 1;

                    // (a + b) + (c + d)
                    answer = op(op(i[0],i[1],a),op(i[2],i[3],b),c);
                    if (answer > 0 && fmod(answer, 1) == 0)
                        h[(int)answer] = 1;
                }
        std::next_permutation(i, i+il);
    }

    // Count through history and return max consecutive number from 1
    for (int n=1; n<hl; n++)
        if (h[n] == 0)
            return n-1;

    return 1;
}

int main()
{
    std::cout << "Project Euler - Problem 93:" << std::endl;
    std::cout << "Find the set of four distinct digits, a < b < c < d, for which the longest set of consecutive positive integers, 1 to n, can be obtained, giving your answer as a string: abcd." << std::endl << std::endl;

    int answer[2] = {2, 1234};

    // Generate all of our integer combinations, and check them
    for (int a = 1; a < 7; a++)
        for (int b = a+1; b < 8; b++)
            for (int c = b+1; c < 9; c++)
                for (int d = c+1; d < 10; d++)
                {
                    int maxInt = arith(a, b, c, d);
                    if (maxInt > answer[0])
                    {
                        answer[0] = maxInt;
                        answer[1] = (a*1000) + (b*100) + (c*10) + d;
                    }
                }

    std::cout << "Solution: " << answer[1] << " (1-" << answer[0] << ")"<< std::endl;
    return 0;
}
