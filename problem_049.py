#!/usr/bin/env python

print("Project Euler - Problem 49:")
print("What 12 digit sequence do you form by concatenating three four-digit primes that are permutations of each other and increase by the same amount?\n")

def arePermutations(a, b, c):
    if sorted(str(a)) != sorted(str(b)): return False
    if sorted(str(b)) != sorted(str(c)): return False
    return True

limit = 10000
primeSieve = [0, 0] + [1] * (limit-2)
primes = []

# Find primes using sieve
for n in range(len(primeSieve)):
    if primeSieve[n] == 1:
        if n > 999:
            primes.append(n)
        m = 2
        while m * n < limit:
            primeSieve[m * n] = 0
            m += 1

solution = "148748178147"
for a in range(len(primes)):
    for b in range(a+1, len(primes)):
        c = primes[b] - primes[a] + primes[b]
        if c > 9999: break
        if c in primes:
            if arePermutations(primes[a], primes[b], c) == True:
                solution = str(primes[a])+str(primes[b])+str(c)
                break
    if solution != "148748178147": break

print(solution)
