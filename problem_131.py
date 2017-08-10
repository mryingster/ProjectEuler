#!/usr/bin/env python

def isPrime (number):
    import math
    limit = int(math.sqrt(number))
    for index in range(3, limit+1, 2):
        if number % index == 0:
            return False
    return True

count = 0
for i in range(1, 577):
    if isPrime((i+1)**3 - i**3):
        count += 1

print count
