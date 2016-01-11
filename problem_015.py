#!/usr/bin/env python

print("Project Euler - Problem 15:")
print("Starting in the top left corner in a 20 by 20 grid, how many routes are there to the bottom right corner?\n")

triangle = [[1,0],[1,1,0]]

# Build pascal's triangle
for r in range(2, 41):
    triangle.append([1])
    for n in range (1, r+1):
        triangle[r].append(triangle[r-1][n] + triangle[r-1][n-1])
    triangle[r].append(0)

# Print middle value of last line
print(triangle[40][20])
