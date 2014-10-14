// -*- compile-command: "gcc -o problem_045 problem_045.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include "ceuler.h"

int main()
{
    long long number  = 40755; // Starting Triangle number
    int triHelp = 286;

    while ( true )
    {
        // get next triangle number
        number += triHelp;
        triHelp++;

        if ( isPentagonal(number) != true ) continue;
        if ( isHexagonal(number)  != true ) continue;
        break;
    }
    printf("Next trigonal, pentagonal, and hexagonal number: %lld\n", number);
    return 0;
}

