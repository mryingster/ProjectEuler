#!/usr/bin/env python

print("Project Euler - Problem 58:")
print("Start with 1 and spiral anticlockwise with numbers incrementing from 1 forming a square. What is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?\n")

def isPrime (n):
    if n < 2: return False
    if n == 2: return True
    if n % 2 == 0: return False

    import math
    for i in range(3, int(math.sqrt(n))+1, 2):
        if n % i == 0:
            return False
    return True

limit = 0.1
diagonalCount = 1
primeCount = 0
proportion = 1
currentPos = 1
sideLength = 2
sideCount = 0

while proportion > limit:
    currentPos += sideLength
    if isPrime(currentPos) == True:
        primeCount += 1
    diagonalCount += 1
    proportion = float(primeCount)/float(diagonalCount)

    sideCount += 1
    if sideCount == 4:
        sideCount = 0
        sideLength += 2

# Add one because sidelength only counts 1 corner
print(sideLength+1)
