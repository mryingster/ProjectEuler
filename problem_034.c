// -*- compile-command: "gcc -o problem_034 problem_034.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int getFactorial(int input)
{
    switch (input)
    {
    case 0: return 1;
    case 1: return 1;
    case 2: return 2;
    case 3: return 6;
    case 4: return 24;
    case 5: return 120;
    case 6: return 720;
    case 7: return 5040;
    case 8: return 40320;
    case 9: return 362880;
    default: return 0;
    }
}

int main()
{
  printf("Project Euler - Problem 34:\n"
         "Find the sum of all numbers which are equal to the sum of the factorial of their digits.\n\n");

  const int maxNum = 1000000;
  int total = 0;
  int number = 0;

  for (number=3 ; number<maxNum ; number++)
  {
      // Calculate the factorials
      int numberSum = 0;
      int decompose = number;
      while (decompose > 0)
      {
          numberSum += getFactorial(decompose % 10);
          decompose /= 10;
      }

      // Compare
      if ( numberSum == number )
          total += numberSum;
    }

      printf("Sum: %d\n", total);

      return 0;
}
