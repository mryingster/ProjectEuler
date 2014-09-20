// -*- compile-command: "gcc -o problem_036 problem_036.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>

bool decIsPalindromic(int input)
{
    int decompose = input;
    int reverse = 0;

    while (decompose > 0)
    {
        reverse *= 10;
        reverse += decompose %10;
        decompose /= 10;
    }

    if ( reverse == input )
        return true;
    return false;
}

bool binIsPalindromic(int *numberIn, int length)
{
    int index = 0;
    int numStart = 0;

    for (numStart=0 ; numberIn[numStart]==0 ; numStart++);
    for (index=numStart ; index<length ; index++)
        if (numberIn[index] != numberIn[length-1-(index-numStart)])
            return false;
    return true;
}

int main()
{
    printf("Project Euler - Problem 36:\n"
           "Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.\n\n");

    const int lenNum = 20;
    int binNum[lenNum];
    int index, number;
    int sum = 0;

    //Clear our binnum
    for (index=0 ; index<lenNum ; index++)
        binNum[index]=0;

    for (number=1 ; number<1000000 ; number++)
    {
        //Increment array to match count
        binNum[lenNum-1] += 1;

        //Carry-over each element if needed
        for (index=lenNum-1 ; index>0 ; index--)
        {
            if (binNum[index] > 1)
            {
                binNum[index-1] += 1;
                binNum[index]   =  0;
            }
        }

        if (decIsPalindromic(number) == true && binIsPalindromic(binNum, lenNum) == true)
        {
            sum += number;

            /*
            //Debug
            printf("Palindrome found: %d; ", number);
            for (index=0 ; index<lenNum ; index++)
                printf("%d", binNum[index]);
            printf("\n");
            */
        }
    }

    printf("Sum: %d\n", sum);

    return 0;
}

