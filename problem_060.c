// -*- compile-command: "gcc -o problem_060 problem_060.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

// Concatinate two integers, and return as an integer
int intCat(int int1, int int2)
{
    int1 *= pow(10, numberOfDigits(int2));
    int1 += int2;
    return int1;
}

// Concatinate two integers (both ways) and check if results are prime
bool testCat(int int1, int int2)
{
    if (isPrime(intCat(int1, int2)) == false) return false;
    if (isPrime(intCat(int2, int1)) == false) return false;
    return true;
}

int findSum(int primes[])
{
    int A;
    for (A = 1; A < 1000; A++)
    {
        int B;
        for (B = A+1; B < 2000; B++)
        {
            if (testCat(primes[A], primes[B]) == false) continue;
            int C;
            for (C = B+1; C < 2000; C++)
            {
                if (testCat(primes[A], primes[C]) == false) continue;
                if (testCat(primes[B], primes[C]) == false) continue;
                int D;
                for (D = C+1; D < 2000; D++)
                {
                    if (testCat(primes[A], primes[D]) == false) continue;
                    if (testCat(primes[B], primes[D]) == false) continue;
                    if (testCat(primes[C], primes[D]) == false) continue;

                    /*
                    // DEBUG - Found Set of four
                    printf("%d, %d, %d, %d (sum: %d)\n",
                           primes[A],primes[B],primes[C],primes[D],
                           primes[A]+primes[B]+primes[C]+primes[D]);
                    */

                    int E;
                    for (E = D+1; E < 2000; E++)
                    {
                        if (testCat(primes[A], primes[E]) == false) continue;
                        if (testCat(primes[B], primes[E]) == false) continue;
                        if (testCat(primes[C], primes[E]) == false) continue;
                        if (testCat(primes[D], primes[E]) == false) continue;

                        /*
                        // DEBUG - Found Set of five
                        printf("%d, %d, %d, %d, %d (sum: %d)\n",
                           primes[A],primes[B],primes[C],primes[D],primes[E],
                           primes[A]+primes[B]+primes[C]+primes[D]+primes[E]);
                        */

                        // Return sum if set of 5 found
                        return primes[A]+primes[B]+primes[C]+primes[D]+primes[E];
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    printf("Project Euler - Problem 60:\n"
           "Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.\n\n");

    int primes[10000] = {2};
    int number=3, index=1;

    while (index < 10000)
    {
        if (isPrime(number))
            primes[index++] = number;
        number+=2;
    }

    int sum = findSum(primes);

    printf("Lowest Sum: %d\n", sum);
    return 0;
}
