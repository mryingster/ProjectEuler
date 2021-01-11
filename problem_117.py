#!/usr/bin/env python

print("Project Euler - Problem 117:")
print("Using a combination of grey square tiles and oblong tiles chosen from: red tiles (measuring two units), green tiles (measuring three units), and blue tiles (measuring four units), how many ways can a row measuring fifty units in length be tiled?\n")

def recurse(a):
    if sum(a) == limit:
        combinations.append(a)
        return
    if sum(a) > limit:
        return

    if len(a) == 0 or a[-1] <= 1:
        recurse(a + [1])
    if len(a) == 0 or a[-1] <= 2:
        recurse(a + [2])
    if len(a) == 0 or a[-1] <= 3:
        recurse(a + [3])
    if len(a) == 0 or a[-1] <= 4:
        recurse(a + [4])

def num_permutations(l):
    numerator = factorials[len(l)]
    denominator = 1
    for i in set(l):
        denominator *= factorials[l.count(i)]
    return numerator / denominator

# Preload factorials
limit = 50
factorials = [1]
for i in range(1, limit + 1):
    factorials.append(factorials[-1] * i)

# Find all combinations with recursion
combinations = []
recurse([])

# Go through combinations and compute permutations
count = 0
for i in combinations:
    count += num_permutations(i)

print(count)
