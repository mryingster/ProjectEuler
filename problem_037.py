#!/usr/bin/env python

print("Project Euler - Problem 37:")
print("Find the sum of the only eleven primes that are both truncatable from left to right and right to left.\n")

def isPrime (number):
    import math
    limit = int(math.sqrt(number))+1
    for index in range(3, limit, 2):
        if number % index == 0:
            return False
    return True

primes = ["2"]
count = 11
sum = 0

for n in range(3, 1000000, 2):
    if isPrime(n) == True:
        nstr = str(n)
        primes.append(nstr)

        found = True
        for i in range(1, len(nstr)):
            if not nstr[i:] in primes:
                found = False
                break
            if not nstr[:i] in primes:
                found = False
                break
        if found == True and n > 10:
            sum += n
            count -= 1

    if count == 0:
        break

print sum
