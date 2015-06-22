#!/usr/bin/env python
from math import sqrt

print("Project Euler - Problem 98")
print("What is the largest word-score for any member of an anagram where both words produce a square word-score?\n")

debug = False

# Read in txt file of words
readFile = open("problem_098.txt")
line = readFile.readline()
import re
line = re.compile("\"").sub(r"", line)
words = line.split(',')

# Search for anagrams, store in dictionary
anagramWords = {}
for i in range(len(words)):
    for n in range(i+1, len(words)):
        if sorted(words[i]) == sorted(words[n]):
            anagramWords.update({words[i]:words[n]})
            break;
if debug == True:
    print(anagramWords)

bestSolution = 0

# Find word scores for each anagram pair, compare with best score
for longestWord, longestDrow in anagramWords.iteritems():
    if debug == True:
        print(longestWord, longestDrow)

    Low = int((sqrt(10**(len(longestWord)-1))))
    High = int((sqrt(10**len(longestWord))))

    Numbers=[]
    for i in range(Low, High):
        tmp = str(i**2)
        if len(tmp) == len(set(tmp)):
            Numbers.append(tmp)

    anagramNumbers = {}

    for i in range(len(Numbers)):
        for n in range(i+1, len(Numbers)):
            if sorted(Numbers[i]) == sorted(Numbers[n]):
                anagramNumbers.update({Numbers[i]:Numbers[n]})
                break;

    if debug == True:
        print(anagramNumbers)

    # Get Word offset values
    WordOffset = ""
    for i in range(len(longestWord)):
        for n in range(len(longestDrow)):
            if longestWord[i] == longestDrow[n]:
                WordOffset = WordOffset+str(n-i)
                break
    if debug == True:
        print WordOffset

    # Get Number Offset Values
    for a, b in anagramNumbers.iteritems():
        NumberOffset = ""
        for i in range(len(a)):
            for n in range(len(b)):
                if a[i] == b[n]:
                    NumberOffset = NumberOffset+str(n-i)
                    break
        if debug == True:
            print(NumberOffset)

        if NumberOffset == WordOffset:
            if debug == True:
                print("Potential Solution: %d %d" % (a, b))
            if max(int(a), int(b)) > int(bestSolution):
                bestSolution = max(int(a), int(b))

print("Largest word-score: %d" % bestSolution)
