#!/usr/bin/env python
import math

print("Project Euler - Problem 27:")
print("Find the product of the coefficients, a and b, for the quadratic expression, n^2 + an + b, that produces the maximum number of primes for consecutive values of n, starting with n = 0.\n")

def isPrime(n):
    if n < 2: return False
    if n == 2: return True
    if n % 2 == 0: return False
    limit = int(math.sqrt(n))
    for index in range(3, limit+1, 2):
        if n % index == 0:
            return False
    return True

answer = [[0, 0, 0]]

for a in range(-1000, 1000):
    for b in range(-1000, 1000):
        n = 0
        quad = (n * n) + (a * n) + b
        while isPrime(quad) == True:
            n += 1
            quad = (n * n) + (a * n) + b
        if n > answer[-1][0]:
            answer.append([n, a, b])

print(answer[-1][1]*answer[-1][2])
