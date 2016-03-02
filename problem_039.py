#!/usr/bin/env python
import math

print("Project Euler - Problem 39:")
print("Find the perimeter of a right triangle (p) that has the most possible solutions, where the perimiter is less than or equal to 1000.\n")

limit = 1000/2
perimeter = {}

for a in range (1, limit):
    for b in range (a, limit):
        c =  math.sqrt((a*a) + (b*b))
        if c < limit:
            if c == int(c):
                sum = a + b + int(c)
                if not sum in perimeter:
                    perimeter.update({sum:0})
                perimeter[sum] += 1

print(sorted(perimeter, key=perimeter.get)[-1])

