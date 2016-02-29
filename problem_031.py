#!/usr/bin/env python

print("Project Euler - Problem 31:")
print("How many different ways can 2 pounds be made using any number of coins?\n")

coins = [1, 2, 5, 10, 20, 50, 100, 200]
ways = [1]

for c in coins:
    for v in range(c, 201):
        while len(ways) <= v: ways.append(0)
        ways[v] += ways[v-c]

print ways[-1]
