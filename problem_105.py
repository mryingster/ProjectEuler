#!/usr/bin/python
import re

print("Project Euler - Problem 105")
print("Using the methods described in problem 103, identify all the special sum sets in the text file containing one-hundred seven to twelve element sets, and return their collective sum.\n")

debug = False

# Check for adherance to both rules for valid sets
# 1. S(B) != S(C); that is, sums of subsets cannot be equal.
# 2. If B contains more elements than C then S(B) > S(C).
def isValid(originalSet):
    # Groups of sums by length
    subSets = [[]]
    for i in range(len(originalSet)):
        subSets.append([])

    # Groups of all sums
    subSetSums = []

    # Create binary mapping to fill our set
    for i in range(1, 2**len(originalSet)):
        currentSet=[]
        for e in range(len(originalSet)):
            setMap = str(bin(i))[2:].zfill(len(originalSet))
            if setMap[e] == "1":
                currentSet.append(originalSet[e])

        subSets[len(currentSet)].append(sum(currentSet))
        subSetSums.append(sum(currentSet))

    # Check property 1
    if len(subSetSums) != len(set(subSetSums)): return False

    # Check property 2
    for i in range(len(originalSet), 2, -1):
        for b in subSets[i]:
            for c in subSets[i-1]:
                if c > b: return False

    return True

# Read in data
data = []
ReadFile = open("problem_105.txt")
line = ReadFile.readline()
while not line == "" :
    line = line.strip()
    line = line.split(",")
    for i in range(len(line)):
        line[i] = int(line[i])
    data.append(line)
    line = ReadFile.readline()

# See if our sets are valid!
validSetSum = 0
for tmpSet in data:
    if isValid(tmpSet) == True:
        if debug == True: print("VALID", tmpSet, sum(tmpSet))
        validSetSum += sum(tmpSet)
    else:
        if debug == True: print("INVALID", tmpSet, sum(tmpSet))

# Print minimum solution as string
print(validSetSum)
