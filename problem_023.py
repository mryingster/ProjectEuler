#!/usr/bin/env python

print("Project Euler - Problem 23:")
print("Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.\n")

limit = 28123

divisorSums = [0] * limit
abundantNumbers = []

# Use seive to find divisor sums
for i in range(1, limit):
    if divisorSums[i] > i:
        abundantNumbers.append(i)
    for n in range(i, limit, i):
        divisorSums[n] += i

# Combine abundant numbers and eliminate abundant sums
nonAbundantSums = [i for i in range(limit)]
for a in range(len(abundantNumbers)):
    for b in range(a, len(abundantNumbers)):
        abundantSum = abundantNumbers[a] + abundantNumbers[b]
        if abundantSum >= limit:
            break

        nonAbundantSums[abundantSum] = 0

print(sum(nonAbundantSums))
