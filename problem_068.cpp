// -*- compile-command: "g++ -std=c++0x -o problem_068 problem_068.cpp ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
#include <string>
#include <iostream>
#include "ceuler.h"

std::string checkSolution(const int o[], const int i[], int length)
{
    std::string result;
    int target = o[0] + i[0] + i[1];

    //Compare each triplet's sum against the first
    for (int p=0; p<length; p++)
    {
        int check[] = {o[p], i[p], i[(p+1)%length]};
        if (check[0] + check[1] + check[2] != target) return "";
        for (int n=0; n<3; n++)
            result += std::to_string(check[n]);
    }

    return result;
}

int main()
{
    std::cout << "Project Euler - Problem 68:" << std::endl;
    std::cout << "Find the maximum concatenation for a 16 digit string for a solution to a \"magic 5-gon ring\" using the numbers 1-10?" << std::endl << std::endl;

    //Do permutations and check answer
    std::string solution;
    int outer[] = {6, 7, 8, 9, 10};
    int length = sizeof(outer)/sizeof(outer[0]);
    while (std::next_permutation(outer, outer+length))
    {
        int inner[] = {1, 2, 3, 4, 5};
        while (std::next_permutation(inner, inner+length))
        {
            solution = checkSolution(outer, inner, length);
            if (!solution.empty()) break;
        }
        if (!solution.empty()) break;
    }

    std::cout << "Solution: " << solution << std::endl;
    return 0;
}
