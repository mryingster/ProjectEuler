#!/usr/bin/env python

print("Project Euler - Problem 10:")
print("Find the sum of all the primes below two million.\n")

limit = 2000000
primes = [0, 0] + [1] * (limit-2)

for i in range(len(primes)):
    if primes[i] == 1:
        primes[i] = i
        n = 2
        while n * i < limit:
            primes[n * i] = 0
            n += 1

print(sum(primes))
