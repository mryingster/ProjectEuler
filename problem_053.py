#!/usr/bin/python
import math

print("Project Euler - Problem 53:")
print("How many, not necessarily distinct, values of  nCr, for 1 <= n <= 100, are greater than one-million?\n")

max=101
solutions=0

for n in range(max):
    for r in range(n):
        if (math.factorial(n)/(math.factorial(r)*math.factorial(n-r))) >= 1000000:
            solutions += 1

print("Total: "+str(solutions))
