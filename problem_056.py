#!/usr/bin/env python

print("Project Euler - Problem 56:")
print("Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?\n")

sums = []
for a in range(100):
    for b in range(100):
        sums.append(sum(int(c) for c in str(a**b)))

print(max(sums))
