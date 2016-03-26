#!/usr/bin/env python

print("Project Euler - Problem 48:")
print("Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.\n")

bigNumber = 0
for i in range(1, 1001):
    bigNumber += i**i

print str(bigNumber)[-10:]
