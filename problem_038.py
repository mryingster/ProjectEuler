#!/usr/bin/env python

print("Project Euler - Problem 38:")
print("What is the largest 1 to 9 pandigital that can be formed by multiplying a fixed number by 1, 2, 3, ...?\n")

def isPandigital(n):
    for i in range(1,10):
        if str(i) not in n:
            return False
    return True

max = 0
for i in range(1, 10000):
    number = ""
    multiplier = 1
    while len(number) < 9:
        number += str(i * multiplier)
        multiplier += 1
    if len(number) == 9 and isPandigital(number) and int(number) > max:
        max = int(number)

print(max)
