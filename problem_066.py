#!/usr/bin/env python
import math

print("Project Euler - Problem 66")
print("Using the equation, x^2 - Dy^2 = 1, find the value of D <= 1000 in minimal solutions of x for which the largest value of x is obtained.\n")

def diophantine(Number, Sqrt_N, debug):
    a = Sqrt_N
    d = 1
    m = 0

    # First Fraction = 1/n^(1/2)
    num0 = a
    den0 = 1

    # Second Fraction = 1/0
    num1 = 1
    den1 = 0

    # Continued fraction until equation equals 1
    while ((num0 ** 2) - (Number * den0 ** 2)) != 1:
        m = d * a - m
        d = (Number - m ** 2) / d
        a = (Sqrt_N + m) / d

        num2 = num1
        den2 = den1

        num1 = num0
        den1 = den0

        num0 = a * num1 + num2
        den0 = a * den1 + den2

    if debug == True:
        print("%s^2 - %s x %s^2" % (num0 , Number, den0)) #DEBUG

    return num0

result = 0
debug = False

for n in range(3, 1001):
    # Skip square numbers
    a = int(math.sqrt(n))
    if a ** 2 == n: continue
    r = diophantine(n, a, debug)

    # Record number
    if r > result:
        result = r

# Print maximum stored result
print("%s" % result)
