#!/usr/bin/env python

print("Project Euler - Problem 5:")
print("What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n")

for number in range(1000, 500000000, 20):
    candidate = True
    for divisor in range(2, 20):
        if number % divisor != 0:
            candidate = False
            break
    if candidate == True:
        break
print("Smallest number: "+str(number))
