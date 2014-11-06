#!/usr/bin/env python

print("Project Euler - Problem 7:")
print("What is the 10,001st prime number?\n")

def isPrime (number):
    import math
    limit = int(math.sqrt(number))
    for index in range(3, limit+1, 2):
        if number % index == 0:
            return False
    return True

prime=3
number=3
count=2

while count < 10001:
    number += 2
    if isPrime(number) == True:
        prime = number
        count += 1

print("10,001st prime: "+str(prime))
