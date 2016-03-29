#!/usr/bin/python

print("Project Euler - Problem 67:")
print("Find the maximum total from top to bottom in a triangle with one-hundred rows.\n")

triangle = []

# Read file in
with open("problem_067.txt") as file:
    while True:
        line = file.readline()
        line = line.strip()
        if line == "": break
        line = line.split(" ")

        # Convert from str to int
        newLine = []
        for i in line:
            newLine.append(int(i))
        triangle.append(newLine)

# Find max sum
for row in range(len(triangle)-2, -1, -1):
    for col in range(len(triangle[row])):
        triangle[row][col] += max(triangle[row+1][col+1], triangle[row+1][col])

print(triangle[0][0])
