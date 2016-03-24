#!/usr/bin/env python

print("Project Euler - Problem 61:")
print("Find the sum of the only ordered set of six cyclic 4-digit numbers for which each polygonal type: triangle, square, pentagonal, hexagonal, heptagonal, and octagonal, is represented by a different number in the set.\n")

# Generate our gonal numbers in the 4 digit range
gonal = []
for i in range(200):
    t = i * (i + 1)/2
    if t > 999 and t < 10000: gonal.append([t, 3])
    t = i * i
    if t > 999 and t < 10000: gonal.append([t, 4])
    t = i * (3*i - 1)/2
    if t > 999 and t < 10000: gonal.append([t, 5])
    t = i * (2*i - 1)
    if t > 999 and t < 10000: gonal.append([t, 6])
    t = i * (5*i - 3)/2
    if t > 999 and t < 10000: gonal.append([t, 7])
    t = i * (3*i - 2)
    if t > 999 and t < 10000: gonal.append([t, 8])

# Compare last 2 and first 2 digits of 2 numbers
def isMatch(a, b):
    if a % 100 == int(str(b)[0:2]):
        return True
    return False

# Iterate through all the numbers looking for cyclical set
def cyclicalSum (gonal):
    for a in gonal:
        history = [a[1], 0, 0, 0, 0, 0]

        for b in gonal:
            if isMatch(a[0], b[0]) and b[1] not in history:
                history[1] = b[1]

                for c in gonal:
                    if isMatch(b[0], c[0]) and c[1] not in history:
                        history[2] = c[1]

                        for d in gonal:
                            if isMatch(c[0], d[0]) and d[1] not in history:
                                history[3] = d[1]

                                for e in gonal:
                                    if isMatch(d[0], e[0]) and e[1] not in history:
                                        history[4] = e[1]

                                        for f in gonal:
                                            if isMatch(e[0], f[0]) and f[1] not in history:
                                                history[5] = f[1]

                                                if isMatch(f[0], a[0]):
                                                    return a[0] + b[0] + c[0] + d[0] + e[0] + f[0]

print(cyclicalSum(gonal))
