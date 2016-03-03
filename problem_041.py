#!/usr/bin/env python

print("Project Euler - Problem 41:")
print("What is the largest n-digit pandigital prime that exists?\n")

def isPandigital(n):
    for i in range(1, len(n)+1):
        if str(i) not in n:
            return False
    return True

limit = 7654321
primes = [1] * limit
largest = 0
for n in range(2, limit):
    if primes[n] == 1:
        if isPandigital(str(n)):
            if largest < n:
                largest = n
        for i in range(n*2, limit, n):
            primes[i] = 0

print(largest)
