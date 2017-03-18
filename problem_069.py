#!/usr/bin/python
import sys, os, math

#Tricky way:
def IsPrime(Input):
    for i in range(2,Input-1):
        if Input % i == 0:
            return 0
    return 1

Goal=1000000
BigNumber=1

for i in range (1, 1000):
    if IsPrime(i)==1:
        WouldBeNumber=BigNumber*i
        if WouldBeNumber>=Goal:
            break
        else:
            BigNumber=WouldBeNumber

print BigNumber

#Brute Force:
"""
def RelativelyPrime(Input, Best):
    count=0

    for PotentialPrime in range(1, Input):
        prime=1

        for j in range(2, Input):
            if Input % j == 0:
                if PotentialPrime % j == 0:
                    #print str(Input)+" Divisible by "+str(j)
                    #print str(PotentialPrime)+" Divisible by "+str(j)
                    prime=0
                    break;
        if prime==1:
            #print "Relatively Prime: "+str(PotentialPrime)
            count+=1

        if float(Input)/float(count)<Best:
            break

    return count

Range=1000
MaxScore=0
MaxN=0

for n in range(2, Range+1):
    #Skip odds!
    if not n % 2 == 0:
        continue

    print n, #Debug Print
    count=RelativelyPrime(n, MaxScore)
    print "Relative Primes: "+str(count), #Debug Print
    score=float(n)/float(count)
    print "Score: "+str(score) #Debug Print

    if score > MaxScore:
        MaxScore=score
        MaxN=n

print "Best Score: "+str(MaxScore)+", n: "+str(MaxN)
"""
