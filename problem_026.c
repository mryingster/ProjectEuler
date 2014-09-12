// -*- compile-command: "gcc -o problem_026 problem_026.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    printf("Project Euler - Problem 26:\n"
           "Find the value of d < 1000 for which 1/d contains the longest recurring cycle.\n\n");

    int n, i, m, j;
    int number[5000] = {};
    int answer[5000] = {};
    int longest[2]   = {};
    int count = 0;

    for (n=1 ; n<1000 ; n++)
    {
        // Clear out number
        for (i=0 ; i<5000 ; i++)
            number[i]=0;
        number[0]=1;

        // Divide 1 by n for whole array
        for (i=0 ; i<5000 ; i++)
	{
            int tmp=number[i]/n, tmp2=tmp*n;
            number[i] -= tmp2;
            if (number[i] < n)
	    {
                number[i+1] += number[i]*10;
                number[i]=0;
	    }
            answer[i]=tmp;
	}

        // Compare Results
        int done=0;
        for (i=3 ; i<4000 ; i++)
	{
            count=0;
            for (m=i+1 ; m<4500 ; m++)
	    {
                count++;
                int candidate=0;
                for (j=0 ; j+m<5000 ; j++)
                    if (answer[i+j] == answer[m+j])
                        candidate=1;
                    else
                    {
                        candidate=0;
                        break;
                    }
                if (candidate == 1)
		{
                    done = 1;
                    break;
		}
	    }
            if (done==1)
                break;
	}

        // Keep track of longest cycle
        if (count > longest[0] && done == 1)
	{
            longest[0]=count;
            longest[1]=n;

            /*
            // DEBUG Print results!
            printf("Repeat found: %i digits produced by 1/%i\n", longest[0], n);

            printf("0.");
            for (i=1 ; i<1000 ; i++)
            {
                if (i%count)
                    printf("%i", answer[i]);
                else
                    printf(" %i", answer[i]);
            }
            printf("...\n");
            */
	}
    }

    printf("Longest: 1/%d produced %i recurring digits\n", longest[1], longest[0]);

    return 0;
}
