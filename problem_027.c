// -*- compile-command: "gcc -o problem_027 problem_027.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>

int isPrime(int input, int *primes)
{
    int n=0;

    if (input == 2)
        return 1;
    else
        while (primes[n] != 0)
        {
            if (input % primes[n] == 0)
                return 0;
            n++;
        }
    return 1;
}

int main()
{
    printf("Project Euler - Problem 27:\n"
           "Find the product of the coefficients, a and b, for the quadratic expression, n^2 + an + b, that produces the maximum number of primes for consecutive values of n, starting with n = 0.\n\n");

    int a=0, b=0, n=0;
    int primeCache[500000] = {};
    int count, candidate;
    int candidate_elements[10] = {};

    primeCache[0]=2;

    for (a=-1000 ; a<1000 ; a++)
    {
        for (b=-1000 ; b<1000 ; b++)
	{
            count=0;
            for (n=0 ; n<100 ; n++)
	    {
                // Formula: n^2 + an + b
                // Use formula to get answer
                int answer=(n*n)+(n*a)+b;

                candidate=0;

                // Check if prime
                int index;
                for (index=0 ; primeCache[index]<=answer ; index++)
		{
                    // Create additional primes in cache if needed
                    if (primeCache[index+1] == 0)
		    {
                        int primesearch=primeCache[index];
                        while (primeCache[index+1]==0)
			{
                            primesearch++;
                            if (isPrime(primesearch, primeCache))
			    {
                                primeCache[index+1]=primesearch;
                                break;
			    }
			}
		    }

                    // Actually check here
                    if (primeCache[index] == answer)
                        candidate=1;

                    if (primeCache[index] > answer)
                        break;
		}

                // If prime, count and go on
                if (candidate==1)
		{
                    count++;

                    // Keep track of best performers
                    if (count > candidate_elements[0])
		    {
                        candidate_elements[0]=count;
                        candidate_elements[1]=a;
                        candidate_elements[2]=b;
                        candidate_elements[3]=n;
                        //printf("Best so far: a=%i, b=%i, produces %i primes (n=%i)\n", candidate_elements[1], candidate_elements[2], candidate_elements[0], candidate_elements[3]); //Debug
		    }
		}
                else
                    break; // Break if not a consecutive prime;
	    }
	}
    }

    printf("Solution: a:%d, b:%d, Product: %d (produces %d primes)\n",
           candidate_elements[1], candidate_elements[2], candidate_elements[1]*candidate_elements[2], candidate_elements[0]);

    return 0;
}

