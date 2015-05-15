#!/usr/bin/env python

def pentagonal(n):
    # the nth pentagonal number is given by (3n^2 - n)/2
    return (n * (3 * n - 1) ) >> 1
 
def generalized_pentagonal(n): # 0, -1, 1, -2, 2
    if n & 1 == 0:
        # pentagonal(n/2 + 1) if n is even
        return pentagonal((n >> 1) + 1)
    else:
        # pentagonal(-(n/2 + 1)) if n is odd
        return pentagonal(-(n >> 1) - 1)
 
def termsign(i):
    if i & 3 < 2:
        return 1 # add if i mod 4 is 0 or 1
    else:
        return -1 # subtract otherwise

print("Project Euler: 78")
print("Let p(n) represent the number of different ways in which n coins can be separated into piles. Find the least value of n for which p(n) is divisible by one million.\n")

pt=[1]
for n in range (1, 100000+1):
     r, i = 0, 0
     while True:
         k = generalized_pentagonal(i)
         if k > n: 
            break
         r += termsign(i) * pt[n - k]
         i += 1
     pt.append(r)
     # print r # DEBUG
     if str(r)[-6:] == "000000":
         break

print("Least value for n: "+str(len(pt)-1))
