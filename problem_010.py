#!/usr/bin/env python

print("Project Euler - Problem 10:")
print("Find the sum of all the primes below two million.\n")

def isPrime (number):
    import math
    limit = int(math.sqrt(number))
    for index in range(3, limit+1, 2):
        if number % index == 0:
            return False
    return True

sum = 2

for number in range(3, 2000000, 2):
    if isPrime(number) == True:
        sum += number

print("Sum of primes: "+str(sum))
