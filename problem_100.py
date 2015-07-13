#!/usr/bin/env python
import sys, os, math
from math import sqrt

print("Project Euler - Problem 98")
print("By finding the first arrangement to contain over 1,000,000,000,000 red and blue discs in total where the probability of taking 2 blue discs at random is 50%, determine the number of blue discs that the box would contain.\n")

def brute():
    b=17.0
    r=5.0

    while 1:
        Probability = (b / (b + r)) * ((b - 1) / (b + r - 1))
        #print("%d, %d, %d\r" % (b, r, Probability)),
        if Probability < .5:
            b += 1.0
        elif Probability == 0.5:
            r += 1.0
        elif Probability > .5:
            r += 1.0
        if r+b > 1000000000000:
            return r+b, b

def diophantine():
    b = 15
    n = 21
    target = 1000000000000

    while n < target:
        bt = 3 * b + 2 * n - 2
        nt = 4 * b + 3 * n - 3
        b = bt
        n = nt

    return n, b

# Get the probability by brute force.
# total, blue = brute()

# Calculate via Diophantine Pairs
# http://oeis.org/A011900
total, blue = diophantine()

print("%d discs (%d total)" % (blue, total))
