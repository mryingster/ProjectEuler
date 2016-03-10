#!/usr/bin/env python

print("Project Euler - Problem 46:")
print("What is the smallest odd, composite number that cannot be written as the sum of a prime and twice a square?\n")

def isPrime (number):
    if number == 2: return True
    import math
    limit = int(math.sqrt(number))
    for index in range(3, limit+1, 2):
        if number % index == 0:
            return False
    return True

key = [0] * 10000

for i in range(1, 10000):
    if isPrime(i) == True:
        s = 1
        n = i + (2 * (s * s))
        while n < 10000:
            key[n] += 1
            s += 1
            n = i + (2 * (s * s))
    else:
        if key[i] == 0 and i % 2 != 0:
            print(i)
            break
