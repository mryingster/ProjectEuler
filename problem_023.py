#!/usr/bin/env python

print("Project Euler - Problem 23:")
print("Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.\n")

def divisorSum(n):
    sum = 0
    if n % 2 != 0 and n % 3 != 0: return 0
    for i in range(1, n/2+1):
        if n % i == 0:
            sum += i
    return sum

limit = 20162

abundant = []
for i in range(2, limit, 1):
    d = divisorSum(i)
    if d > i: abundant.append(i)

abundantSums = [False] * limit
for a in abundant:
    for b in abundant:
        if a+b > limit-1: break
        abundantSums[a+b] = True

sum = 0
for i in range(len(abundantSums)):
    if abundantSums[i] == False:
        sum += i

print(sum)
