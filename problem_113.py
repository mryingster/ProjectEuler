#!/usr/bin/env python

print("Project Euler - Problem 113:")
print("How many numbers below a googol (10^100) are not bouncy?\n")

def factorial(n):
    f = 1
    while n > 0:
        f *= n
        n -= 1
    return f

def choose(n, k):
    num = factorial(n)
    den = factorial(k) * factorial(n-k)
    return num/den

digits = 100

ascending = choose(digits + 9, 9)
descending = choose(digits + 10, 10)
duplicates = 2 + (10 * digits)

print(ascending + descending - duplicates)

