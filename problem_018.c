// -*- compile-command: "gcc -o problem_018 problem_018.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>

int main()
{
    int i = 0,  j = 0,  n = 0;
    int largest   = 0;
    int candidate = 0;

    int myArray[15][15]={
        {75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {95,64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {17,47,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {18,35,87,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {20, 4,82,47,65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {19, 1,23,75, 3,34, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {88, 2,77,73, 7,63,67, 0, 0, 0, 0, 0, 0, 0, 0},
        {99,65, 4,28, 6,16,70,92, 0, 0, 0, 0, 0, 0, 0},
        {41,41,26,56,83,40,80,70,33, 0, 0, 0, 0, 0, 0},
        {41,48,72,33,47,32,37,16,94,29, 0, 0, 0, 0, 0},
        {53,71,44,65,25,43,91,52,97,51,14, 0, 0, 0, 0},
        {70,11,33,28,77,73,17,78,39,68,17,57, 0, 0, 0},
        {91,71,52,38,17,14,91,43,58,50,27,29,48, 0, 0},
        {63,66, 4,68,89,53,67,30,73,16,69,87,40,31, 0},
        {04,62,98,27,23, 9,70,98,73,93,38,53,60, 4,23}
    };

    int binaryPath[16] = {0};

    printf("Project Euler - Problem 18:\n"
           "Find the maximum total from top to bottom of the triangle below:\n\n"
           "                            75\n"
           "                          95  64\n"
           "                        17  47  82\n"
           "                      18  35  87  10\n"
           "                    20  04  82  47  65\n"
           "                  19  01  23  75  03  34\n"
           "                88  02  77  73  07  63  67\n"
           "              99  65  04  28  06  16  70  92\n"
           "            41  41  26  56  83  40  80  70  33\n"
           "          41  48  72  33  47  32  37  16  94  29\n"
           "        53  71  44  65  25  43  91  52  97  51  14\n"
           "      70  11  33  28  77  73  17  78  39  68  17  57\n"
           "    91  71  52  38  17  14  91  43  58  50  27  29  48\n"
           "  63  66  04  68  89  53  67  30  73  16  69  87  40  31\n"
           "04  62  98  27  23  09  70  98  73  93  38  53  60  04  23\n\n");

    while (binaryPath[0] != 1)
    {
        //Carry over addition
        for (j=15 ; j>=0 ; j--)
            if (binaryPath[j]>1)
            {
                binaryPath[j]=binaryPath[j]-2;
                binaryPath[j-1]=binaryPath[j-1]+1;
            }

        /*
        // DEBUG: Print path and sum
        for (n=0 ; n<16 ; n++)
            printf("%i",binaryPath[n]);
        printf(" - %i\n", candidate);
        */

        //Follow Path
        candidate=0;
        n=0;

        for (i=15 ; i>0 ; i--)
	{
            if (binaryPath[i] == 1)
                n=n+1;
            candidate=candidate+myArray[15-i][n];
            //printf("%i\n",myArray[15-i][n]); //Debug
	}

        //Compare if larger
        if (candidate > largest)
            largest=candidate;

        //Increase binaryPath by 1
        binaryPath[15]=binaryPath[15]+1;
    }
    printf("Largest sum: %i\n", largest);
    return 0;
}
