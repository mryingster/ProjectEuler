#!/usr/bin/python
from math import sqrt
import re

#Primes to compute
ComputePrimes=1000000

def IsPrime(number):
    if number == 2: return True
    if number % 2 == 0: return False

    index = 0
    search = int(sqrt(number))
    for index in range(3, search, 2):
        if number % index == 0 : return False
    return True

Primes=[]

#Generate Primes (Skipping 2)
print "Computing primes..."
for i in range(3, 9000, 2):
    if i==5 :continue; # 5 Never works....
    if IsPrime(i):
        Primes.append(i)
#print Primes

print "Generating table..."
#Make big table
Candidates=[]
for i in range(9001):
    Candidates.append([i])

print "Finding answers..."
#Get list of all primes that fit with eachother
for a in Primes:
    for aa in Primes:
        if IsPrime(int(str(a)+str(aa))):
            if IsPrime(int(str(aa)+str(a))):
                Candidates[a].append(aa)

#print Candidates
#print len(Candidates)

print "Shortening list..."
#Remove elements with fewer than 5 items
popped=0
for i in range(len(Candidates)):
    i-=popped
    if len(Candidates) <= i:
        break
    if len(Candidates[i]) < 5:
        Candidates.pop(i)
        popped+=1

#print Candidates
#print len(Candidates)

print "Finding intersections..."
#Find lists with 5 olverlapping elements
Test={}
for a in range(len(Candidates)):

    for b in range(len(Candidates)):
        if a >= b: continue;
        if len(set(Candidates[a]).intersection(Candidates[b])) < 2: continue;

        for c in range(len(Candidates)):
            if b >= c: continue;
            if len(set(Candidates[a]).intersection(Candidates[b],Candidates[c])) < 3: continue;

            for d in range(len(Candidates)):
                if c >= d: continue;
                if len(set(Candidates[a]).intersection(Candidates[b],Candidates[c],Candidates[d])) < 4: continue;

                for e in range(len(Candidates)):
                    if d >= e: continue
                    if len(set(Candidates[a]).intersection(Candidates[b],Candidates[c],Candidates[d],Candidates[e])) < 5: continue;

                    #print Test
                    print "Intersection:",
                    print set(Candidates[a]).intersection(Candidates[b],Candidates[c],Candidates[d],Candidates[e])
                    print "Sum:",
                    print sum(set(Candidates[a]).intersection(Candidates[b],Candidates[c],Candidates[d],Candidates[e]))
                    quit()

"""
INTERSECTION set([6733, 5701, 8389, 5197, 13])
Sum: 26033
Time: 1m43.538s
"""
