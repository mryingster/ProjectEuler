#!/usr/bin/env python

def s(n):
    a = 1
    i = 1
    while a % n != 0:
        i += 1
        a *= i
        pass
    return i

def primeFactorSieve(limit):
    primeFactors = [[] for i in range(limit)]
    factorials   = [0 for i in range(limit)]

    for i in range(2, limit):
        # Non-prime
        if len(primeFactors[i]) != 0:
            # Decide which set of factors is the highest
            candidates = []
            for f in set(primeFactors[i]):
                n = f ** primeFactors[i].count(f)
                if factorials[n] != 0:
                    candidates.append(factorials[n])
                else:
                    candidates.append(s(n))
                pass
            factorials[i] = max(candidates)
            continue

        # Prime - Complete factorization for larger numbers
        factorials[i] = i
        q = i
        while q < limit:
            for m in range(q, limit, q):
                primeFactors[m].append(i)
                pass
            q *= i
            pass
        pass
    return primeFactors, factorials

print("Project Euler - Problem 549:\n"
      "Find the sum of s(n) where s(n) is the smallest number m such that n divides m! for 2 < n < 10^8.\n")

debug = False
limit = 10**8 + 1
primefactors, factorials = primeFactorSieve(limit)

if debug == True:
    for i in range(limit):
        print("%4d  %10d  %s" % (i, factorials[i], primefactors[i]))

print(sum(factorials))
