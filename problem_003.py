#!/usr/bin/env python

print("Project Euler - Problem 3:")
print("What is the largest prime factor of the number 600851475143 ?\n")

number = 600851475143
lastFactor = 0

for i in range(2, 10000):
    if ( number % i == 0 ):
        number /= i
        lastFactor = i
        i = 2

print("Largest factor found: "+str(lastFactor))
