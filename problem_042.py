#!/usr/bin/env python
import re

print("Project Euler - Problem 42:")
print("In a list of two-thousand common English words, how many are triangle words?\n")

# Process input data
ReadFile = open("problem_042.txt")
data = ReadFile.readline()
data = re.compile('"').sub(r"", data)
data = data.split(",")
data = sorted(data)

def wordScore(n):
    value = 0
    for i in n:
        value += ord(i) - ord('@')
    return value

# Generate triangle numbers
triangles = [1]
for n in range(2, 100):
    triangles.append(triangles[-1]+n)

# Score words and see if they are triangle values
count = 0
for i in range(len(data)):
    score = wordScore(data[i])
    if score in triangles:
        count += 1

print(count)
