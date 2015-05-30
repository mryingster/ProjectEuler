#!/usr/bin/env python
import sys, os, math

def IsPrime(Input):
    for i in range(2, Input):
        if Input%i == 0:
            return 0
    return 1

print("Project Euler - Problem 87")
print("How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?\n")

debug = False

# Calculate Maximums
Max = 50000000
# Too much to calculate, so hardcoding values in
AMax = 7071 + 1 #50000000^1/2
BMax = 368 + 1  #50000000^1/3
CMax = 84 + 1   #50000000^1/4

# Calculate Primes into List
if debug == True: print "Calculating primes up to "+str(AMax)

Primes=[2]
for i in range(3,AMax+100,2):
    if IsPrime(i)==1:
        Primes.append(i)

A = -1
B = 0
C = 0

Answers = {}

if debug == True: print("Calculating answers")
while 1:
    A += 1
    Total = Primes[A]**2 + Primes[B]**3 + Primes[C]**4

    if Total >= Max:
        A = -1
        B += 1
        if Primes[B] > BMax:
            if debug == True: print("%d %d %d" % (B, Primes[B], BMax))
            B = 0
            C += 1
        if Primes[C] > CMax:
            if debug == True: print("%d %d %d" % (C, Primes[C], CMax))
            break
        continue
    else:
        Answers.update({Total:1})
        if debug == True:
            print("%d^2 + %d^3 + ^d^4 = %d" % (Primes[A], Primes[B], Primes[C], Total))

print("Total unique: %d" % len(Answers))
