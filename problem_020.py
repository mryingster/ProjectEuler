#!/usr/bin/env python

print("Project Euler - Problem 20:")
print("Find the sum of the digits in the number 100!\n")

def factorial(n):
    for m in range(n-1, 0, -1):
        n *= m
    return n

sum = 0
for i in str(factorial(100)):
    sum += int(i)

print(sum)
