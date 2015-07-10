#!/usr/bin/env python

print("Project Euler - Problem 25:")
print("What is the index of the first term in the Fibonacci sequence to contain 1000 digits?\n")

a = 1
b = 0
c = 0
index = 1
debug = False

while len(str(a)) < 1000:
    c = a
    a += b
    b = c
    index += 1
    if debug == True: print index, a

print("%d" % index)
