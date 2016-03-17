#!/usr/bin/env python
import math, re

print("Project Euler - Problem 102")
print("Using the given 27K text file containing the co-ordinates of one thousand \"random\" triangles, find the number of triangles for which the interior contains the origin.\n")

debug = False
count = 0

def containsOrigin(a1, a2, b1, b2, c1, c2):
    if b1 == c1 or c1 == a1 or b1 == a1:
        if debug == True: print("INVALID-----------------------------------------")
        return 0

    inside=1

    ABSlope=float((b2-a2)/(1.0*b1-a1))
    ABY=float(a2-(ABSlope*a1))
    if debug == True: print("AB: y =", ABSlope, "x +", ABY)
    if not ABY < 0 and ABSlope*c1+ABY-c2 < 0 or not ABY > 0 and ABSlope*c1+ABY-c2 > 0 :
        inside = 0

    ACSlope=float((c2-a2)/(1.0*c1-a1))
    ACY=float(a2-(ACSlope*a1))
    if debug == True: print("AC: y =", ACSlope, "x +", ACY)
    if not ACY < 0 and ACSlope*b1+ACY-b2 < 0 or not ACY > 0 and ACSlope*b1+ACY-b2 > 0 :
        inside = 0

    CBSlope=float((b2-c2)/(1.0*b1-c1))
    CBY=float(c2-(CBSlope*c1))
    if debug == True: print("CB: y =", CBSlope, "x +", CBY)
    if not CBY < 0 and CBSlope*a1+CBY-a2 < 0 or not CBY > 0 and CBSlope*a1+CBY-a2 > 0 :
        inside = 0

    if inside == 1:
        if debug == True: print("Origin is contained in triangle")
        return 1
    else:
        if debug == True: print("Fail")
        return 0

with open("problem_102.txt") as f:
    line = "start"
    while line != "":
        line = f.readline()
        line = line.strip()
        if line == "": break
        if debug == True: print(line, "\t",)
        a1 = int(re.compile("([^,]*),.*").sub(r"\1", line))
        a2 = int(re.compile("[^,]*,([^,]*),.*").sub(r"\1", line))
        b1 = int(re.compile("[^,]*,[^,]*,([^,]*),.*").sub(r"\1", line))
        b2 = int(re.compile("[^,]*,[^,]*,[^,]*,([^,]*),.*").sub(r"\1", line))
        c1 = int(re.compile("[^,]*,[^,]*,[^,]*,[^,]*,([^,]*),.*").sub(r"\1", line))
        c2 = int(re.compile("[^,]*,[^,]*,[^,]*,[^,]*,[^,]*,([^,]*).*").sub(r"\1", line))
        count += containsOrigin(a1, a2, b1, b2, c1, c2)

print(count)
