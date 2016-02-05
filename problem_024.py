#!/usr/bin/env python
import re, itertools

print("Project Euler - Problem 24:")
print("Find the 1,000,000th lexiconic permutation of the numbers 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.\n")

answer = list(itertools.permutations([0,1,2,3,4,5,6,7,8,9]))[1000000]

print(re.compile('[(, )]').sub(r"", str(answer)))
