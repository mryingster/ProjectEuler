#!/usr/bin/env python
import re

print("Project Euler: 22")
print("Sort 5000 names and calculate the sum of their name scores.\n")

ReadFile = open("problem_022.txt")
data = ReadFile.readline()
data = re.compile('"').sub(r"", data)
data = data.split(",")
data = sorted(data)

def nameScore(n):
    value = 0
    for i in n:
        value += ord(i) - ord('@')
    return value

total = 0
for i in range(len(data)):
    score = nameScore(data[i])
    #print(data[i], i+1, score, (i+1)*score) # Debug
    total += (i+1)*score

print(total)
