#!/usr/bin/env python

def numberOfHexagons(l, t):
    hexagons = 0 # Hexagons found for givin triangle length, l
    l -= 2       # Usable length for hexagon placement
    m = 1        # Multiplier for rotations available of larger hexagons

    while l > 0:
        hexagons += m * t[l]
        l -= 3
        m += 1

    return hexagons

print("Project Euler 577:")
print("An equilateral triangle is divided into equilateral triangles. Using the lattice points, it is possible to create a hexagon by connecting six points contained in the triangle. Find the sum of hexagons contained in triangles with side length equal to 3 through 12345.\n")

limit = 12345
debug = False

# Precompute triangle numbers
triangles = [0]
for i in range(1, limit):
    triangles.append(triangles[i-1] + i)

sums = [0, 0, 0]
for n in range(3, limit + 1):
    sums.append(numberOfHexagons(n, triangles))
    if debug == True:
        print("Side Length: %d, Hexagons: %d" % (n, sums[n]))

print(sum(sums))
