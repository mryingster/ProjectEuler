#!/usr/bin/env python

print("Project Euler - Problem 71:")
print("By listing the set of reduced proper fractions for d <= 1,000,000 in ascending order of size, find the numerator of the fraction immediately to the left of 3/7.\n")

target = float(3)/float(7)
closest = {"numerator":   0,
           "denominator": 0,
           "fraction":    0}

for d in range(2, 1000000):
    n = int(target * d) - 1
    f = float(n)/float(d)
    if f == target:
        continue
    if f > closest["fraction"]:
        closest.update({"numerator":   n,
                        "denominator": d,
                        "fraction":    f})

print(closest["numerator"])
