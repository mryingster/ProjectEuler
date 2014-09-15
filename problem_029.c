// -*- compile-command: "gcc -o problem_029 problem_029.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    printf("Project Euler - Problem 29:\n"
           "How many distinct terms are in the sequence generated by a^b for a <= 100 and b <= 100?\n\n");

    unsigned long long bigNumHistory[25][9802]={{}};
    unsigned long long bigNumCurrent[25]={};
    int a=0, b=0;
    int m=0, k=0;
    int historyCount=0, count=0;

    for (a=2 ; a<=100 ; a++)
    {
        // Clear out bigNumCurrent Array
        for (m=24 ; m>0 ; m--)
            bigNumCurrent[m]=0;
        bigNumCurrent[24]=a;

        for (b=2 ; b<=100 ; b++)
	{
            // Multiply current array elements by a
            for (m=24 ; m>0 ; m--)
                bigNumCurrent[m] *= a;

            // Roll over large numbers to next element
            for (m=24 ; m>0 ; m--)
                while (bigNumCurrent[m] >= 1000000000)
		{
                    bigNumCurrent[m] -= 1000000000;
                    bigNumCurrent[m-1] += 1;
		}

            // Check bigNumHistory for similar numbers
            int isDifferent = 0;
            for (k=0 ; k<=historyCount ; k++)
	    {
                isDifferent = 0;
                for (m=24 ; m>0 ; m--)
                    if (bigNumCurrent[m] != bigNumHistory[m][k])
                        isDifferent=1;
                if (isDifferent == 0) break;
	    }

            // Keep count of unique numbers
            if (isDifferent == 1)
                count++;

            // Record number to bigNumHistory
            historyCount++;
            for (m=24 ; m>=0 ; m--)
                bigNumHistory[m][historyCount]=bigNumCurrent[m];
	}
    }

    printf("Total distinct terms: %d\n", count);

    return 0;
}
