#!/usr/bin/env python

def rotate(n):
    t = int(str(n)[-1]+str(n)[:-1])
    return t

print("Project Euler - Problem 35:")
print("How many circular primes are there below one million?\n")

count = 0
limit = 1000000
primes = [0, 0] + [1] * (limit-2)

for n in range(len(primes)):
    # Find primes using sieve
    if primes[n] == 1:
        primes[n] = n
        m = 2
        while m * n < limit:
            primes[m * n] = 0
            m += 1

for i in range(len(primes)):
    if primes[i] == 0:
        continue

    candidate = True

    n = rotate(i)
    while n != i:
        if primes[n] == 0:
            candidate = False
            break
        n = rotate(n)

    if candidate == True:
        count += 1

print(count)
