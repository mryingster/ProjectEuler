// -*- compile-command: "gcc -std=c11 -o problem_074 problem_074.c ceuler.c -Wall -lm" -*-
// Copyright (c) 2017 Michael Caldwell
#include <stdio.h>
#include "ceuler.h"

unsigned long long factorial_sum(unsigned long long n) {
    unsigned long long sum = 0;
    int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    while (n > 0) {
        sum += factorial[n % 10];
        n /= 10;
    }

    return sum;
}

bool contains(unsigned long long c[50], unsigned long long n) {
    for (int i=0; i<50; i++) {
        if (c[i] == n) {
            return true;
        }
    }
    return false;
}

int main() {
    printf("Project Euler - Problem 74:\n");
    printf("How many factorial chains, with a starting number below one million, contain exactly sixty non-repeating terms?\n\n");

    int history[1000000] = {};
    int history_len = sizeof(history)/sizeof(history[0]);
    int count = 0;

    for (int i=1; i<1000000; i++) {
        unsigned long long  n = i;
        unsigned long long c[50] = {};
        int c_index = 0;

        while (true) {
            // Keep track of new numbers
            if (contains(c, n)) {
                history[i] = c_index;
                break;
            }

            // Keep track of numbers we've seen in our history
            if (n < history_len) {
                if (history[n] > 0) {
                    history[i] = history[n] + c_index;
                    break;
                }
            }

            // Get next factorial sum
            c[++c_index] = n;
            n = factorial_sum(n);
        }
    }

    //Look through history for non-repeating == 60
    for (int i=1; i<history_len; i++) {
        if (history[i] == 60) {
            count++;
        }
    }

    printf("%d\n", count);
}
