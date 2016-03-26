#!/usr/bin/env python

print("Project Euler - Problem 47:")
print("What is the first of four consecutive integers to have four distinct prime factors?\n")

limit = 500000
primeSieve = [0, 0] + [1] * (limit-2)
primes = []

# Find primes using sieve
for n in range(len(primeSieve)):
    if primeSieve[n] == 1:
        primes.append(n)
        m = 2
        while m * n < limit:
            primeSieve[m * n] = 0
            m += 1

def destinctPrimeFactors(n, primes):
    factors = []
    for p in primes:
        if n % p == 0:
            factors.append(p)
            while n % p == 0:
                n /= p
        if n <= 1: break
    return factors

target = 4
answer = 0
for i in range(2, limit):
    if len(destinctPrimeFactors(i, primes)) == target:
        if answer == 0:
            answer = i
        if i - answer == target - 1:
            break
    else:
        answer = 0

print(answer)
