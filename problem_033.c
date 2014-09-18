// -*- compile-command: "gcc -o problem_033 problem_033.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int isprime(int input)
{
    bool prime = false;
    int  index;
    for (index=2 ; index < input ; index++)
    {
        if (input % index != 0)
            prime= true;
        else
        {
            prime= false;
            break;
	}
    }

    if (prime == true || input == 2)
        return 1;
    return 0;
}


int main()
{
    printf("Project Euler - Problem 33:\n"
           "Find the product of all the two digit fractions with an unorthodox canceling method.\n\n");

    bool   success;
    int    totalNum  = 1,     totalDen  = 1;
    int    numBig[2] = {1,0}, denBig[2] = {1,0};
    float  bigNum    = 10.0,  bigDen    = 10.0;
    float  smallNum  = 0.0,   smallDen  = 0.0;
    int    i, n, m, j;
    double big, small;

    for (i=11 ; i<100 ; i++)
    {
        bigNum += 1.0;
        numBig[1] += 1;
        if (numBig[1]>9)
	{
            numBig[1] -= 10;
            numBig[0] += 1;
	}
        bigDen = 10.0;
        denBig[0] = 1;
        denBig[1] = 0;

        for (n=11 ; n<100 ; n++)
	{
            bigDen += 1.0;
            denBig[1] += 1;
            if (denBig[1]>9)
	    {
                denBig[1] -= 10;
                denBig[0] += 1;
	    }
            smallNum = 0.0;

            for (m=1 ; m<10 ; m++)
	    {
                smallNum += 1.0;
                smallDen = 0.0;
                for (j=1 ; j<10 ; j++)
		{
                    smallDen += 1.0;
                    big = bigNum/bigDen;
                    small = smallNum/smallDen;
                    success = false;
                    if (big == small)
		    {
                        //printf("%f/%f = %f/%f\n", bigNum, bigDen, smallNum, smallDen);
                        if (/*numBig[0]!=1 && */ numBig[1]!=0 && big<1)
			{
                            if (numBig[0]==denBig[0] && numBig[1]==m && denBig[1]==j)
                                success = true;
                            if (numBig[0]==denBig[1] && numBig[1]==m && denBig[0]==j)
                                success = true;
                            if (numBig[1]==denBig[0] && numBig[0]==m && denBig[1]==j)
                                success = true;
                            if (numBig[1]==denBig[1] && numBig[0]==m && denBig[0]==j)
                                success = true;
			}

                        // If unorthodox canceling, add product
                        if (success == true)
			{
                            printf("%i/%i = %i/%i\n", i, n, m, j);
                            totalNum *= i;
                            totalDen *= n;
			}
		    }
		}
	    }
	}
    }

    printf("\nThe product of all unorthodox canceling fractions: %i/%i\n", totalNum, totalDen);

    for (i=1000 ; i>1 ; i--)
        if (i < totalNum)
            if (isprime(i))
            {
                while ( totalNum > 1 )
                {
                    if ( totalNum % i )
                        break;
                    else
                        if ( totalDen % i != 0)
                            break;
                        else
                        {
                            totalNum /= i;
                            totalDen /= i;
                            //printf("(%i/%i) %i/%i\n", i, i, totalNum, totalDen);
                        }
                }
            }

    printf("Which simplified, is: %i/%i\n", totalNum, totalDen);

    return 0;
}
