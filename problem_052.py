#!/usr/bin/env python

print("Project Euler - Problem 52:")
print("Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.\n")

answer = 0

for x in range(1000000):
    sig = sorted(str(x))
    for n in range(2, 7):
        if sig == sorted(str(x * n)):
            answer = x
        else:
            answer = 0
            break

    if answer != 0:
        break

print(answer)
