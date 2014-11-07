#!/usr/bin/env python
import math

print("Project Euler - Problem 9:")
print("There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.\n")

a=1
product = 0
while True:
    a+=1
    b=a
    while True:
        b+=1
        c = math.sqrt(a**2 + b**2)
        if a + b + c > 1000: break
        if c != int(c): continue
        #print a, b, c # DEBUG
        if a + b + c == 1000: product = int(a * b * c)
    if product != 0: break

print("Product: "+str(product))
