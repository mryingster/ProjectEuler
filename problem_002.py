#!/usr/bin/env python

print("Project Euler - Problem 2")
print("By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\n")

fib = 1
hist = 1
sum = 0

while (fib < 4000000):
    #print(fib) --DEBUG
    tmp = fib
    fib = fib + hist
    hist = tmp
    if (fib % 2 == 0):
        sum += fib

print("Sum: "+str(sum))
