// -*- compile-command: "gcc -std=c99 -o problem_078 problem_078.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2018 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

int pentagonal(int n) {
    // the nth pentagonal number is given by (3n^2 - n)/2
    return (n * (3 * n - 1) ) >> 1;
}

int generalized_pentagonal(int n){ // 0, -1, 1, -2, 2
    if ((n & 1) == 0)
        // pentagonal(n/2 + 1) if n is even
        return pentagonal((n >> 1) + 1);
    else
        // pentagonal(-(n/2 + 1)) if n is odd
        return pentagonal(-(n >> 1) - 1);
}

int termsign(int i) {
    if ((i & 3) < 2)
        return 1; // add if i mod 4 is 0 or 1
    else
        return -1; // subtract otherwise
}

void bigNumCarry(int a[], int length){
    for (int index=0; index<length; index++)
        while (a[index] > 9) {
            a[index]   -= 10;
            a[index+1] += 1;
        }
}

void bigNumCopy(int a1[], int a2[], int length) {
    for (int index=0; index<length; index++)
        a2[index] = a1[index];
}

void bigNumAdd(int a1[], int a2[], int length) {
    for (int index=0; index<length; index++)
        a1[index] += a2[index];
    bigNumCarry(a1, length);
}

void bigNumMultiply(int a1[], int m, int length) {
    for (int index=0; index<length; index++)
        a1[index] *= m;
    bigNumCarry(a1, length);
}

void bigNumPrint(int a[], int length) {
    for (int index=0; index<length; index++)
        printf("%d", a[index]);
    printf("\n");
}

int main() {
    printf("Project Euler - Problem 78:\n"
           "Let p(n) represent the number of different ways in which n coins can be separated into piles. Find the least value of n for which p(n) is divisible by one million.\n\n");

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);


    int (*pt)[100000][512];
    pt = malloc(sizeof(*pt));
    *pt[0][0] = 1;
    int pt_len = 512;
    int pt_index = 0;

    for (int n=1; n<=100000; n++) {
        int (*r)[512];
        r = malloc(sizeof(int) * pt_len);
        int i = 0;

        while (true) {
            int k = generalized_pentagonal(i);
            if (k > n)
                break;
            int (*t)[512];
            t = malloc(sizeof(int) * pt_len);
            bigNumCopy(*pt[n-k], *t, pt_len);
            bigNumMultiply(*t, termsign(i), pt_len);
            bigNumAdd(*r, *t, pt_len);
            free(t);
            i++;
        }

        printf("%d", n);
        bigNumCopy(*r, *pt[++pt_index], pt_len);
        bigNumPrint(*r, pt_len);

        bool finished = true;
        for (int j=0; j<6; j++) {
            if (*r[j] != 0) {
                finished = false;
                break;
            }
        }

        free(r);

        if (finished == true)
            break;
    }

    printf("%d\n", pt_index);
    printElapsedTime(start);

    free(pt);
    return 0;
}

//257 chars
//36325300925435785930832331577396761646715836173633893227071086460709268608053489541731404543537668438991170680745272159154493740615385823202158167635276250554555342115855424598920159035413044811245082197335097953570911884252410730174907784762924663654000000
//Least value for n: 55374
