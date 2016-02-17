#!/usr/bin/env python

print("Project Euler - Problem 5:")
print("What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n")

def isPrime (number):
    if number < 2: return False
    if number == 2: return True
    if number % 2 == 0: return False
    import math
    limit = int(math.sqrt(number))
    for index in range(3, limit+1, 2):
        if number % index == 0:
            return False
    return True

# Calculate base number
base = 1
for i in range(1, 20):
    if isPrime(i):
        base *= i

# Multiply base number until we arrive at an answer
for m in range(1, 1000):
    number = base * m
    candidate = True
    for divisor in range(11, 20):
        if number % divisor != 0:
            candidate = False
            break
    if candidate == True:
        break

print(number)
