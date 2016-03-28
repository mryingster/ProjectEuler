#!/usr/bin/env python
import math

print("Project Euler - Problem 64:")
print("How many continued fractions for N <= 10000 have an odd period?\n")

count = 0
for S in range(10000):
    a0 = int(math.sqrt(S))
    if a0**2 == S: continue

    period = 0
    m1 = 0
    d1 = 1
    a1 = a0

    # From Wikipedia: https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Example.2C_square_root_of_114_as_a_continued_fraction
    #
    # m1 = d0 * a0 - m0
    # d1 = S - m1^2 / d0
    # a1  = a0 + m1 / d1

    while a1 != (a0 * 2):
        m1 = d1 * a1 - m1
        d1 = (S - m1 ** 2) / d1
        a1 = (a0 + m1) / d1
        period += 1

    if period %2 != 0:
        count += 1

print(count)
