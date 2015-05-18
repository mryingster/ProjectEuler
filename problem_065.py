#!/usr/bin/env python
import math

### Notes ###
#                         (m)
# Multipliers: 2   1   2   1   1   4   1   1   6   1   1
# Numerators:  2   3   8   11  19  87 106 193
#             (c) (b) (a)
#
# To calculate position a, a=b*m+c
# This starts by calculating the second numerator (3),
# and assumes 1 for the numerator to the left of 2
# Multiplier continue in the same pattern of increasing by 2

print("Problem 65:")
print("Find the sum of the numerator of the 100th convergent fraction for e.\n")

a = 2
b = 1
c = 0
Multiplier = 0
Count = 2
NumCount = 1
debug = False

while NumCount < 100:
    # Keep track of multipliers
    if Count == 3:
        Count = 1
        Multiplier += 2
        m = Multiplier
    else:
        Count += 1
        m = 1

    c = b
    b = a
    a = b * m + c

    NumCount += 1

    if debug == True:
        print("%d = %d * %d + %d" % (a, b, m, c))
        print("%d, %d" % (a, NumCount))

# Find the sume of the digits of the final numerator
Answer = 0
while a > 0:
    Answer = Answer + a % 10
    a = a / 10

print("Sum of the 100th Numerator: %d" % (Answer))
