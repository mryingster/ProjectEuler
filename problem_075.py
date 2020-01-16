#!/usr/bin/env python
import math

print("Project Euler - Problem 75:")
print("Given that L is the length of the wire, for how many values of L <= 1,500,000 can exactly one integer sided right angle triangle be formed?\n")

def gcd(a,b):
    while b > 0:
        a, b = b, a % b
    return a

debug = False
limit = 1500000
sqr_limit = int(math.sqrt(limit/2))
history = {}

for m in range(2, sqr_limit):
    for n in range(1, m):
        # Euclid's Formula:
        # If sides m and n add up to be odd and the greatest common
        # denominator of n/m is 1 then we have a pythagorean triple
        if (m+n) % 2 == 1 and gcd(n, m) == 1:
            a = (m*m) - (n*n)
            b = 2 * m * n
            c = (m*m) + (n*n)
            L = a + b + c
            if debug == True:
                print("%d: %d, %d, %d\n" % (L, a, b, c))
            # Keep track of all multiples of triple so we don't have to calculate them later
            while L < limit:
                count = 1
                if L in history:
                    count = history[L] + 1
                history.update({L:count})
                L += a + b + c;

# Count results
count = 0
for i in sorted(history.keys()):
    if debug == True:
        print i, history[i]
    if i > limit:
        break
    if history[i] > 1:
        continue
    count += 1

print(count)
