#!/usr/bin/python
import math, re

file = "problem_099.txt"

print("Project Euler - Problem 99")
print("In the textfile, %s, find the line in which the base-exponent pair have the largest computed value.\n" % file)

BaseExpFile = open(file)
LineNumber = 0
MaxLine = 0
MaxValue = 0
debug = False

while 1:
    Line = BaseExpFile.readline()
    if not Line: break
    LineNumber += 1
    Line = re.compile("\n").sub(r"",Line)
    x = float(re.compile("([^\,]*)\,.*").sub(r"\1",Line))
    y = float(re.compile("[^\,]*\,(.*)").sub(r"\1",Line))
    LineValue=y*math.log(x)
    if debug == True:
        print(LineNumber, x, y, LineValue)
    if LineValue > MaxValue:
        MaxValue = LineValue
        MaxLine = LineNumber

print("Maximum value, %d, found on line %d." % (MaxValue, MaxLine))
