#!/usr/bin/env python

print("Project Euler - Problem 16:")
print("What is the sum of the digits of the number 2^1000\n")

sum = 0
for i in str(2**1000):
    sum += int(i)

print(sum)
