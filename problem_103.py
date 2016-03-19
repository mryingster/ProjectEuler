#!/usr/bin/python

print("Project Euler - Problem 103")
print("The optimum set for n = 6 is A = {11, 18, 19, 20, 22, 25}, with S(A) = 115 and corresponding set string: 111819202225. Given that A is an optimum special sum set for n = 7, find its set string.\n ")

debug = False

# find next near-optimum solution
def nearOptimum(lastSet):
    newSet = []
    newSet.append(lastSet[len(lastSet)/2])
    for i in range(len(lastSet)):
        newSet.append(newSet[0]+lastSet[i])
    return newSet

# Check for adherance to both rules for valid sets
# 1. S(B) != S(C); that is, sums of subsets cannot be equal.
# 2. If B contains more elements than C then S(B) > S(C).
def isValid(originalSet):
    # Groups of sums by length
    subSets = [[],[],[],[],[],[],[],[]]

    # Groups of all sums
    subSetSums = []

    # Create binary mapping to fill our set
    for i in range(1, 128):
        currentSet=[]
        for e in range(len(originalSet)):
            setMap = str(bin(i))[2:].zfill(7)
            if setMap[e] == "1":
                currentSet.append(originalSet[e])

        subSets[len(currentSet)].append(sum(currentSet))
        subSetSums.append(sum(currentSet))

    # Check property 1
    if len(subSetSums) != len(set(subSetSums)): return False

    # Check property 2
    for i in range(6, 2, -1):
        for b in subSets[i]:
            for c in subSets[i-1]:
                if c > b: return False

    return True

# Generate sets for n=1 through n = 5
sets = [[1]]
for i in range(1, 5):
    sets.append(nearOptimum(sets[-1]))

# They give us the optimum result for n = 6
sets.append([11, 18, 19, 20, 22, 25])

# Generate near optimum set for n = 7
sets.append(nearOptimum(sets[-1]))

# Print our sets!
if debug == True:
    for Aset in sets:
        print(Aset, sum(Aset))

minimum = sum(sets[-1])
optimum = sets[-1]

# Create an offset array to check for better solutions using
# brute force by combining the offset and near optimum arrays.
offset = [0, -3, -3, -3, -3, -3, -3]
while offset[0] == 0:
    offset[6] += 1
    for i in range(6, 0, -1):
        if offset[i] == 3:
            offset[i] = -3
            offset[i-1] += 1

    # Skip if our offset will make our sum larger than the minimum
    if sum(offset) + sum(sets[-1]) >= minimum: continue

    # Copy last set, combine with offset
    tmpSet = sets[-1][:]
    for i in range(7):
        tmpSet[i] += offset[i]

    # See if our new set is valid!
    if isValid(tmpSet) == True:
        if debug == True: print(tmpSet, sum(tmpSet))
        if sum(tmpSet) < minimum:
            optimum = tmpSet[:]
            minimum = sum(tmpSet)

# Print minimum solution as string
print(str(optimum[0])+str(optimum[1])+str(optimum[2])+
      str(optimum[3])+str(optimum[4])+str(optimum[5])+
      str(optimum[6]))
