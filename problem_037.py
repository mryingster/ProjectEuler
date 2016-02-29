#!/usr/bin/env python

print("Project Euler - Problem 37:")
print("Find the sum of the only eleven primes that are both truncatable from left to right and right to left.\n")

limit = 1000000
primes = [0, 0] + [1] * (limit-2)
count = 11
sum = 0

for n in range(len(primes)):
    # Find primes using sieve
    if primes[n] == 1:
        primes[n] = n
        m = 2
        while m * n < limit:
            primes[m * n] = 0
            m += 1

        # Look for truncatability
        found = True
        nstr = str(n)
        for i in range(1, len(nstr)):
            if primes[int(nstr[i:])] == 0:
                found = False
                break
            if primes[int(nstr[:i])] == 0:
                found = False
                break

        # Record results
        if found == True and n > 10:
            sum += n
            count -= 1
            if count == 0:
                break

print(sum)
