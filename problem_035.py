#!/usr/bin/env python
import math

print("Project Euler - Problem 35:")
print("How many circular primes are there below one million?\n")

def isPrime (n):
    if n < 2: return False
    if n == 2: return True
    if n % 2 == 0: return False
    limit = int(math.sqrt(n))
    for index in range(3, limit+1, 2):
        if n % index == 0:
            return False
    return True

def isCircular(i):
    n = str(i)
    for j in range(len(n)-1):
        n = n[-1]+n[:-1]
        if isPrime(int(n)) == False:
            return False
    return True

count = 0
limit = 1000000
for i in range(limit):
    if isPrime(i) == True:
        if isCircular(i) == True:
            count += 1

print(count)
