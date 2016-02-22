#!/usr/bin/env python

print("Project Euler - Problem 36:")
print("Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.\n")

sum = 0
for n in range(1000000):
    bn = bin(n)[2:]
    if bn == str(bn)[::-1]:
        if n == int(str(n)[::-1]):
            sum += n

print(sum)
