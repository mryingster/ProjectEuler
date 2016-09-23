#!/usr/bin/env python

print("Project Euler - Problem 347")
print("Find the sum of all numbers less than 10,000,000 that are divisible by 2 distinct primes, and are the maximum number that can be created using those 2 primes.\n")

plimit = 10000000

# Find primes using sieve
primeSieve = [0, 0] + [1] * (plimit - 1)
for n in range(len(primeSieve)):
    if primeSieve[n] == 1:
        primeSieve[n] = [n]
        m = 2
        while m * n < len(primeSieve):
            primeSieve[m * n] = [n, m]
            m += 1

# Prime Factorization - Store sets of 2 into dictionary
results = {}
for n in range(2, len(primeSieve)):
    if len(primeSieve[n]) == 2:
        temp = primeSieve[primeSieve[n][1]]
        primeSieve[n].pop()
        primeSieve[n] += temp
        temp = list(set(primeSieve[n]))
        if len(temp) == 2:
            results.update({str(temp):n})

# Sum Results
sum = 0
for i in results:
    sum += results[i]

print sum
