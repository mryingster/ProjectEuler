#!/usr/bin/env python

print("Project Euler - Problem 28:")
print("Starting with the number 1 and moving to the right in a clockwise direction, form a 1001 by 1001 spiral. What is the sum of the numbers on the diagonals in this spiral?\n")


limit = 1001 ** 2
n = 1
sum = 1
step = 2
c = 0

while n < limit:
    n += step
    sum += n
    c += 1
    if c == 4:
        c = 0
        step += 2

print sum
