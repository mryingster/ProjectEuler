#!/usr/bin/env python

print("Project Euler - Problem 188")
print("Find the last 8 digits of the tetration of 1777^^1855\n")

def tetration(n, e, mod):
    r = 1
    for i in range(e):
        r = pow(n, r, mod)
    return r

print tetration(1777, 1855, 100000000)
