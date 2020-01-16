#!/usr/bin/env python

print("Project Euler - Problem 76:")
print("How many different ways can one hundred be written as a sum of at least two positive integers?\n")

limit = 100
ways = [1] + [0] * limit

for n in range(1, limit):
    for v in range(n, limit + 1):
        ways[v] += ways[v-n]

print ways[-1]
