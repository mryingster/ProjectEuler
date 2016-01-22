#!/usr/bin/env python

print("Project Euler - Problem 21:")
print("Evaluate the sum of all the amicable numbers under 10000.\n")

def divisorSum(n) :
    s = 0
    for i in range(1, n/2+1):
        if n % i == 0:
            s += i
    return s

sum = 0

for n in range(10000):
    d = divisorSum(n)
    if n == d: continue
    dd = divisorSum(d)

    if dd == n:
        #print n, d, dd
        sum += n

print(sum)
