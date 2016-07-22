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
multiplier = 0
count = 2
debug = False

# Starting 2 steps in
for i in range(2, 101):
    # Keep track of multipliers
    if count == 3:
        count = 1
        multiplier += 2
        m = multiplier
    else:
        count += 1
        m = 1

    # Continued Fraction
    c = b
    b = a
    a *= m
    a += c

    if debug == True:
        print("%d = %d * %d + %d" % (a, b, m, c))
        print("%d, %d" % (a, i))

# Find the sum of the digits of the final numerator
answer = 0
for i in str(a): answer += int(i)
print(answer)
