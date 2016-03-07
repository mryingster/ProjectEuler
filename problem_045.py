#!/usr/bin/env python

print("Project Euler - Problem 45:")
print("Find the next triangle number after 40755 that is also pentagonal and hexagonal.\n")

answer = 0
t, tn = 285, 40755
p, pn = 165, 40755
h, hn = 143, 40755
while True:
    t += 1
    tn = t * (t + 1) / 2
    while pn < tn:
        p += 1
        pn = p * (3 * p - 1) / 2
    while hn < tn:
        h += 1
        hn = h * (2 * h - 1)
    if tn == hn and tn == pn:
        answer = tn
        break

print(answer)
