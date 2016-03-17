#!/usr/bin/env python

print("Project Euler - Problem 1")
print("If we are presented with the first k terms of a sequence it is impossible to say with certainty the value of the next term, as there are infinitely many polynomial functions that can model the sequence.\n")
print("Find the sum of the First Incorrect Terms (FITs) for the following equation, un = 1 - n + n2 - n3 + n4 - n5 + n6 - n7 + n8 - n9 + n10, for each value of n, where n represents the number of terms given in the series.\n")

# Generate our sequence to 10 terms (Number of greatest power)
sequence = [[]]
for n in range(1,11):
    sequence[0].append(1 - n + n**2 - n**3 + n**4 - n**5 + n**6 - n**7 + n**8 - n**9 + n**10)

# Build a difference pyramid
for y in range(1,10):
    sequence.append([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
    for x in range(y,10):
        sequence[y][x] = sequence[y-1][x] - sequence[y-1][x-1]

# Sum it all up!
total = 0
for row in sequence:
    total += sum(row)

print(total)
