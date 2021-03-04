#!/usr/bin/env python

print("Project Euler - Problem 4:")
print("Find the largest palindrome made from the product of two 3-digit numbers.\n")

result = 0

for a in range(100, 999):
    for b in range(a, 999):
        product = a*b
        if product > result:
            if (product == int(str(product)[::-1])):
                result = product

print(result)
