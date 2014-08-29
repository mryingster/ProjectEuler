// -*- compile-command: "gcc -o problem_002 problem_002.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
  printf("Project Euler - Problem 2:\n");
  printf("By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\n\n");

    int i, previousNum=0, nextNum=0, currentNum=1, total;

    previousNum=0;
    currentNum=1;
    nextNum=0;

    for (i=0; i<10000; i++)
    {
        nextNum=previousNum+currentNum;
        previousNum=currentNum;
        currentNum=nextNum;
        if (currentNum < 4000000)
        {
            if ( currentNum % 2 )
                printf("");
            else
                total=total+currentNum;
        }
        else
            break;
      }

    printf("Sum: \033[1m%i\033[0m\n", total);

    return 0;
}
