#!/usr/bin/env python

print("Project Euler - Problem 686:")
print("Find the 678910th power of 2 to start with the digits 123.\n")

search = str(123)
count = 678910
power = 1
n = 2

while count > 0:
    n *= 2
    power += 1
    if str(n).startswith(search):
        count -= 1

    while n > 1000000000000000000000:
        n /= 10

print("Power: %s" % power)
