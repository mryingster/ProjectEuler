#!/usr/bin/env python

print("Project Euler - Problem 6:")
print("Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n")

sumsquares = 0
squaresums = 0

for number in range(1, 101):
    squaresums += number

squaresums = squaresums * squaresums

for number in range(1, 101):
    sumsquares += (number * number)

result = squaresums - sumsquares

print("Difference: "+str(result))
