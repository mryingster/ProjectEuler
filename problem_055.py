#!/usr/bin/env python

print("Project Euler - Problem 55:")
print("How many Lychrel numbers are there below ten-thousand?\n")

count = 0
limit = 10000

for n in range(limit):
    for tries in range(51):
        n += int(str(n)[::-1])
        if str(n) == str(n)[::-1]:
            count += 1
            break

print(limit - count)
