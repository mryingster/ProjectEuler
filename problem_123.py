#!/usr/bin/python
from math import sqrt

def CalcRemainder(pn, n):
    result=((pn-1)**n+(pn+1)**n)%pn**2
    return result

def IsPrime(n):
    if n == 2 or n == 3:
        return True
    elif n < 2 or n % 2 == 0:
        return False
    elif n < 9:
        return True
    elif n % 3 == 0:
        return False
    r = int(sqrt(n))
    f = 5
    while f <= r:
        if n % f == 0 or n % (f + 2) == 0:
            return False
        else:
            f += 6
    return True

print("Project Euler 123:")
print("Let pn be the nth prime, and let r be the remainder when (pn-1)^n + (pn+1)^n is divided by pn^2. Find the least value of n for which the remainder first exceeds 10^10\n")

#Start at a higher known...
n  = 7037
pn = 71059
debug = False

while 1:
    if debug == True: print(n, pn)

    Value = CalcRemainder(pn, n)

    if debug == True: print(Value)

    if Value > 10**10:
        break

    #Increment to next N and Pn, skip every other one...
    for i in 1, 2:
        n += 1
        while 1:
            pn += 1
            if IsPrime(pn):
                break

print n, pn, Value
#21035 237737 10001595590, 7m39.363s
