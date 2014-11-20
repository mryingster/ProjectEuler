#!/usr/bin/python
import math

print("Project Euler - Problem 66")
print("Using the equation, x^2 - Dy^2 = 1, find the value of D <= 1000 in minimal solutions of x for which the largest value of x is obtained.\n")

number = 2
largest_number = 0
largest_x = 0

while number < 1000:
    number += 1
    # Skip square numbers
    a0 = int(math.sqrt(number))
    if a0 ** 2 == number: continue

    d = 1
    m = 0
    a = a0

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

    #print "%s^2 - %s x %s^2" % (num0 , number, den0) #DEBUG

    # Record largest number
    if num0 > largest_x:
        largest_x = num0
        largest_number = number

print "Max: %s (%s)" % ( largest_number, largest_x )
