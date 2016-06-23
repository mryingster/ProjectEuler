#!/usr/bin/env python
import math

print("Project Euler - Problem 66")
print("Using the equation, x^2 - Dy^2 = 1, find the value of D <= 1000 in minimal solutions of x for which the largest value of x is obtained.\n")

def diophantine(a, debug):
    d = 1
    m = 0

    num1 = 1
    num0 = a
    den1 = 0
    den0 = 1

    # Continued fraction until equation equals 1
    while ((num0 ** 2) - (number * den0 ** 2)) != 1:
        m = d * a - m
        d = (number - m * m) / d
        a = (a0 + m) / d

        num2 = num1
        num1 = num0
        den2 = den1
        den1 = den0

        num0 = a * num1 + num2
        den0 = a * den1 + den2

    if debug == True:
        print("%s^2 - %s x %s^2" % (num0 , number, den0)) #DEBUG

    return num0

results = [0, 0, 0]
debug = False

for number in range(3, 1001):
    # Skip square numbers
    a0 = int(math.sqrt(number))
    if a0 ** 2 != number:
        result = diophantine(a0, debug)
    else:
        result = 0

    # Record number
    results.append(result)

# Print maximum stored result
print("%s (%s)" % (results.index(max(results)), max(results)))
