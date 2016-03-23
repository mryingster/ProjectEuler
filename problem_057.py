#!/usr/bin/python

print("Project Euler - Problem 57:")
print("In the first one-thousand expansions of 1+1/(2+1/(2+1/(2+...)))=1.414213, how many fractions contain a numerator with more digits than denominator?\n")

count = 0
num = 3
den = 2
for i in range(1000):
    num, den = (den * 2) + num, num + den
    if len(str(num)) > len(str(den)):
        count += 1

print count
