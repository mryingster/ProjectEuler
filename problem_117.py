#!/usr/bin/env python

def recurse(a, limit):
    if sum(a) == limit:
        return[a]

    if sum(a) > limit:
        return []

    combinations = []
    if len(a) == 0 or a[-1] <= 1:
        combinations += recurse(a + [1], limit)
    if len(a) == 0 or a[-1] <= 2:
        combinations += recurse(a + [2], limit)
    if len(a) == 0 or a[-1] <= 3:
        combinations += recurse(a + [3], limit)
    if len(a) == 0 or a[-1] <= 4:
        combinations += recurse(a + [4], limit)
    return combinations

def num_permutations(l, factorials):
    numerator = factorials[len(l)]
    denominator = 1
    for i in set(l):
        denominator *= factorials[l.count(i)]
    return numerator / denominator

def __main__():
    limit = 50

    print("Project Euler - Problem 117:")
    print("Using a combination of grey square tiles and oblong tiles chosen from: red tiles (measuring two units), green tiles (measuring three units), and blue tiles (measuring four units), How many ways can a row measuring fifty units in length be tiled?\n")

    # Recurse to find tile combinations
    combinations = recurse([], limit)

    # Preload factorials
    factorials = [1]
    for i in range(1, limit + 1):
        factorials.append(factorials[-1] * i)

    # Go through combinations and permute them
    count = 0
    for i in combinations:
        count += num_permutations(i, factorials)

    print(count)

__main__()
