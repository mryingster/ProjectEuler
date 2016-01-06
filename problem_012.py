#!/usr/bin/env python

print("Project Euler - Problem 12:\n")
print("What is the value of the first triangle number to have over five hundred divisors?\n")

def isPrime (n):
    if n < 2: return False
    if n == 2: return True

    import math
    for i in range(3, int(math.sqrt(n))+1, 2):
        if n % i == 0:
            return False
    return True


def findDivisors(n, primes):
    divisors = {}
    p = 0
    while p < len(primes) and n > 1:
        if n % primes[p] == 0:
            n /= primes[p]
            if p in divisors:
                divisors.update({p:divisors[p]+1})
            else:
                divisors.update({p:2})
        else:
            p += 1

    result = 1
    for i in divisors:
        result *= divisors[i]

    return result


primes = []
for n in range(2000):
    if isPrime(n) == True:
        primes.append(n)

divisors = 1
triangle = 1
n = 1
while divisors < 500:
    n += 1
    triangle += n
    if triangle % 10 != 0: continue
    divisors = findDivisors(triangle, primes)

print(triangle)
