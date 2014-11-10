// -*- compile-command: "g++ -o problem_061 problem_061.cpp -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <iostream>
#include <vector>
#include <stdio.h>

void printVector(std::vector<int> numbers)
{
    int length = numbers.size();
    for (int index = 0; index < length; index++)
        printf("%d, ", numbers.at(index));
    printf("\n");
}

bool chains(int a, int b)
{
    return ( a % 100 == b / 100 );
}

int findSum(std::vector<int> numbers[])
{
    // Go through all triangle numbers one at a time
    for (size_t i = 0 ; i < numbers[0].size() ; i++)
    {
        int tri = numbers[0][i];
        // Set up vector vector of non-triangle values
        std::vector<std::vector<int> > set;
        set.push_back(numbers[1]);
        set.push_back(numbers[2]);
        set.push_back(numbers[3]);
        set.push_back(numbers[4]);
        set.push_back(numbers[5]);
        // Go through each member for set looking for a viable chain option
        for (size_t setA = 0 ; setA < set.size() ; setA++)
            for (size_t setAIndex = 0 ; setAIndex < set[setA].size() ; setAIndex++)
                // If we find a match, do the whole thing again, but remove the set from which we found a match!
                if (chains(tri, set[setA][setAIndex]))
                {
                    int A = set[setA][setAIndex];
                    // Set up vector vector of non-triangle values
                    std::vector<std::vector<int> > set;
                    set.push_back(numbers[1]);
                    set.push_back(numbers[2]);
                    set.push_back(numbers[3]);
                    set.push_back(numbers[4]);
                    set.push_back(numbers[5]);
                    //Remove matching set
                    set.erase(set.begin()+setA);
                    // Go through each member for set looking for a viable chain option
                    for (size_t setB = 0 ; setB < set.size() ; setB++)
                        for (size_t setBIndex = 0 ; setBIndex < set[setB].size() ; setBIndex++)
                            // If we find a match, do the whole thing again, but remove the set from which we found a match!
                            if (chains(A, set[setB][setBIndex]))
                            {
                                int B = set[setB][setBIndex];
                                // Set up vector vector of non-triangle values
                                std::vector<std::vector<int> > set;
                                set.push_back(numbers[1]);
                                set.push_back(numbers[2]);
                                set.push_back(numbers[3]);
                                set.push_back(numbers[4]);
                                set.push_back(numbers[5]);
                                //Remove matched sets
                                set.erase(set.begin()+setA);
                                set.erase(set.begin()+setB);
                                // Go through each member for set looking for a viable chain option
                                for (size_t setC = 0 ; setC < set.size() ; setC++)
                                    for (size_t setCIndex = 0 ; setCIndex < set[setC].size() ; setCIndex++)
                                        // If we find a match, do the whole thing again, but remove the set from which we found a match!
                                        if (chains(B, set[setC][setCIndex]))
                                        {
                                            int C = set[setC][setCIndex];
                                            // Set up vector vector of non-triangle values
                                            std::vector<std::vector<int> > set;
                                            set.push_back(numbers[1]);
                                            set.push_back(numbers[2]);
                                            set.push_back(numbers[3]);
                                            set.push_back(numbers[4]);
                                            set.push_back(numbers[5]);
                                            //Remove matched sets
                                            set.erase(set.begin()+setA);
                                            set.erase(set.begin()+setB);
                                            set.erase(set.begin()+setC);
                                            // Go through each member for set looking for a viable chain option
                                            for (size_t setD = 0 ; setD < set.size() ; setD++)
                                                for (size_t setDIndex = 0 ; setDIndex < set[setD].size() ; setDIndex++)
                                                    // If we find a match, do the whole thing again, but remove the set from which we found a match!
                                                    if (chains(C, set[setD][setDIndex]))
                                                    {
                                                        int D = set[setD][setDIndex];
                                                        // Set up vector vector of non-triangle values
                                                        std::vector<std::vector<int> > set;
                                                        set.push_back(numbers[1]);
                                                        set.push_back(numbers[2]);
                                                        set.push_back(numbers[3]);
                                                        set.push_back(numbers[4]);
                                                        set.push_back(numbers[5]);
                                                        //Remove matched sets
                                                        set.erase(set.begin()+setA);
                                                        set.erase(set.begin()+setB);
                                                        set.erase(set.begin()+setC);
                                                        set.erase(set.begin()+setD);
                                                        // Go through each member for set looking for a viable chain option
                                                        for (size_t setE = 0 ; setE < set.size() ; setE++)
                                                            for (size_t setEIndex = 0 ; setEIndex < set[setE].size() ; setEIndex++)
                                                                // If we find a match, do the whole thing again, but remove the set from which we found a match!
                                                                if (chains(D, set[setE][setEIndex]) && chains(set[setE][setEIndex], tri))
                                                                {
                                                                    int E = set[setE][setEIndex];
                                                                    //printf("%d %d %d %d %d %d\n", tri, A, B, C, D, E);
                                                                    return tri+A+B+C+D+E;
                                                                }
                                                    }
                                        }
                            }
                }
    }
    return 0;
}

int main()
{
    printf("Project Euler - Problem 61:\n"
           "Find the sum of the only ordered set of six cyclic 4-digit numbers for which each polygonal type: triangle, square, pentagonal, hexagonal, heptagonal, and octagonal, is represented by a different number in the set.\n\n");

    std::vector<int> numbers[6];

    // Generate Numbers, store in vector
    int tri = 0, number = 0;
    while (tri < 10000)
    {
        number++;
        tri = number * (number + 1) / 2;
        if (tri > 1000 && tri < 10000) numbers[0].push_back(tri);

        int sqr = number * number;
        if (sqr > 1000 && sqr < 10000) numbers[1].push_back(sqr);

        int pen = number * (3 * number - 1) / 2;
        if (pen > 1000 && pen < 10000) numbers[2].push_back(pen);

        int hex = number * (2 * number - 1);
        if (hex > 1000 && hex < 10000) numbers[3].push_back(hex);

        int hep = number * (5 * number - 3) / 2;
        if (hep > 1000 && hep < 10000) numbers[4].push_back(hep);

        int oct = number * (3 * number - 2);
        if (oct > 1000 && oct < 10000) numbers[5].push_back(oct);
    }

    /* // DEBUG Print Array/Vector
    for (int number = 0; number<6; number++)
    {
        printf("Array: %d------\n", number);
        printVector(numbers[number]);
    }
    */

    printf("Sum: %d\n", findSum(numbers));

    return 0;
}
