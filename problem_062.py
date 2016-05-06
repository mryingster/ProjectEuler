#!/usr/bin/env python
import math

print("Project Euler - Problem 62:")
print("Find the smallest cube for which exactly five permutations of its digits are cube.\n")

# Take number and generate signature
def GenerateNumber(Input):
    Out = 0
    while Input > 0:
        Digit = Input%10
        Out = Out + 10**Digit
        Input = Input / 10
    return Out

Results={}

# Look for cubes and put their signatures into results
for i in range(2, 10000):
    Number = GenerateNumber(i**3)
    if Number in Results:
        Count = Results[Number] + 1
        Results.update({Number:Count})
        if Count == 5: break 
    else:
        Results.update({Number:1})

#Found 5 permutations!
#print i, Number, Count

#print Results

#Go through and find fist appearence of permutation
for i in range(2,10000):
    Number = GenerateNumber(i**3)
    if Number == 1111212111:
        print("Smallest Cube: %d (%d^3)" % (i**3, i))
        break
