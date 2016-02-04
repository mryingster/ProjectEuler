#!/usr/bin/env python

print("Project Euler - Problem 29:")
print("How many distinct terms are in the sequence generated by a^b for 2 <= a <= 100 and 2 <= b <= 100?\n")

answers = []
for a in range(2, 101):
    for b in range(2, 101):
        n = a**b
        if not n in answers:
            answers.append(n)

print(len(answers))