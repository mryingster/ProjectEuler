#!/usr/bin/python
import re

print("Project Euler - Problem 106:")
print("For n = 12, how many of the 261625 subset pairs that can be obtained need to be tested for equality? (See problem 103, 105)\n")

debug = False
limit = 12
mySet = []

# Make out set for n=limit
for n in range(limit):
    mySet.append(n+1)

# Create binary mapping to fill our subsets
subSets = []
for i in range(1, 2**len(mySet)):
    currentSet = []

    setMap = str(bin(i))[2:].zfill(len(mySet))
    for e in range(len(mySet)):
        if setMap[e] == "1":
            currentSet.append(mySet[e])
    subSets.append(currentSet)

# Go through all sets and compare them
count = 0
needToCheck = 0
for a in range(len(subSets)):
    for b in range(a+1, len(subSets)):
        if set(subSets[a]).intersection(subSets[b]) == set([]):
            count += 1

            # Only check similarly sizes sets > 1
            if len(subSets[a]) == len(subSets[b]) and len(subSets[a]) > 1:
                if debug == True: print(subSets[a], subSets[b])

                # Since sets are ordered, and set a is larger than set b,
                # if any element of set b is larger than respective element
                # of set a, then it is uncertain. Count it!
                for i in range(len(subSets[a])):
                    if subSets[a][i] < subSets[b][i]:
                        needToCheck += 1
                        break

if debug  == True: print(count)
print(needToCheck)
