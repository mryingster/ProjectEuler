#!/usr/bin/env python

def totient(n, primes, minimum):
    result = n
    threshold = n/minimum
    i = 0

    while n > 1 and i < len(primes):
        if n % primes[i] == 0:
            while n % primes[i] == 0:
                n /= primes[i]
            result *= 1 - (1.0/float(primes[i]))
            if result <= threshold:
                return 1;
        i += 1

    return int(result)

print("Project Euler - Problem 70:")
print("Find the value of n, 1 < n < 10^7, for which phi(n) is a permutation of n and the ratio n/phi(n) produces a minimum.\n")

limit = 10000000
plimit = 5000 # Rounding up from sqrt limit

# Find primes using sieve
primeSieve = [0, 0] + [1] * (plimit)
primes = []
for n in range(len(primeSieve)):
    if primeSieve[n] == 1:
        primes.append(n)
        m = 2
        while m * n < len(primeSieve):
            primeSieve[m * n] = 0
            m += 1
    if len(primes) == 5000 :
        break

smallest_ratio = 2.0
smallest_phi = 1
smallest_n = 1
for a in range(100, len(primes)):
    for b in range(a, len(primes)):
        n = primes[a] * primes[b]
        if n > limit:
            break

        phi = totient(n, primes, smallest_ratio)
        ratio = float(n)/float(phi)

        if ratio < smallest_ratio:
            if sorted(str(phi)) == sorted(str(n)) :
                smallest_ratio = ratio
                smallest_phi = phi
                smallest_n = n
                #print(n, phi, ratio)

print(smallest_n)

