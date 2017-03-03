#!/usr/bin/env python
import math

print("Project Euler - Problem 116:")
print("How many different ways can the black tiles in a row measuring fifty units in length be replaced by red tiles (2 units), green tiles (3 units), and blue tiles (4 units) if colours cannot be mixed and at least one coloured tile must be used?\n")

def factorial(n):
    f = 1
    while n > 0:
        f *= n
        n -= 1
    return f

def choose(n, k):
    num = factorial(n)
    den = factorial(k) * factorial(n-k)
    return num/den

space = 50
tiles = {"red":2,
         "green":3,
         "blue":4}
totalWays = 0
debug = False

for color in tiles:
    maxColoredTiles = int(math.floor(space/tiles[color]))
    for coloredTiles in range(1, maxColoredTiles + 1):
        blackTiles = space - (coloredTiles * tiles[color])
        ways = choose(blackTiles + coloredTiles, coloredTiles)
        totalWays += ways
        if debug == True:
            print("Black: %d, %s: %d, Positions: %d" % (blackTiles, color, coloredTiles, ways))

print(totalWays)
