#!/usr/bin/python
import os, sys, math

FLAT       = 0
INCREASING = 1
DECREASING = 2
BOUNCY     = 3

def isNumberBouncy(input):
    n = str(input)
    type = FLAT

    for i in range(1, len(n)):
        if n[i-1] < n[i]:
            if type == DECREASING:
                return True
            type = INCREASING

        if n[i-1] > n[i]:
            if type == INCREASING:
                return True
            type = DECREASING

    return False

print("Project Euler 112:")
print("Find the least number for which the proportion of bouncy numbers is exactly 99%.\n")

debug = False
bouncy = 0
percent = 0

n = 0
while percent < 99:
    n += 1
    bouncy += isNumberBouncy(n)
    percent = float(bouncy) / float(n)*100

if debug == True:
    print("Bouncy Numbers: %d" % bouncy)
    print("Percent:        %d" % percent)

print(n)
