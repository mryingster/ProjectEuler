#!/usr/bin/env python
import re

def FindShortNumber(Input):
    debug = False

    StartLength = len(str(Input))

    Output = re.compile('VIIII').sub(r"IX", Input)
    Output = re.compile('IIII').sub(r"IV", Output)
    Output = re.compile('LXXXX').sub(r"XC", Output)
    Output = re.compile('XXXX').sub(r"XL", Output)
    Output = re.compile('DCCCC').sub(r"CM", Output)
    Output = re.compile('CCCC').sub(r"CD", Output)

    if debug == True: print("%s, %s" % (Input, Output))
    EndLength = len(str(Output))
    return StartLength - EndLength

print("Project Euler - Problem 89")
print("Find the number of characters saved by writing each of these one thousand Roman numerals in their minimal form.\n ")

RomanNumerals = open("problem_089.txt")

CharsSaved = 0
while 1:
    line = RomanNumerals.readline()
    if not line: break
    line = re.compile('\r|\n').sub(r"", line)
    CharsSaved += FindShortNumber(line)

print("%d characters saved" % CharsSaved)
