#!/usr/bin/python
import sys, os, math

def isPrime(n):
    if n < 2: return False
    if n == 2: return True
    if n % 2 == 0: return False

    limit = int(math.sqrt(n)) + 1

    for i in range(3, limit, 2):
        if n % i == 0:
            return False
    return True

print("Project Euler - Problem 69:")
print("Find the value of n <= 1,000,000 for which n/phi(n) is a maximum, where phi(n) is Euler's Totient function.\n")

goal = 1000000
bigNumber = 1

for n in range (1, 1000):
    if isPrime(n) == True:
        wouldBeNumber = bigNumber * n
        if wouldBeNumber >= goal:
            break
        else:
            bigNumber = wouldBeNumber

print bigNumber
