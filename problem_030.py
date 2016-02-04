#!/usr/bin/env python

print("Project Euler - Problem 30:")
print("Find the sum of all the numbers that can be written as the sum of fifth powers of their digits\n")

answer = 0
limit = 6*9 ** 5
for n in range(2, limit):
    s = 0
    for d in str(n):
        s += int(d)**5
    if n == s:
        answer += n

print answer
