#!/usr/bin/env python

print("Project Euler - Problem 32:")
print("Find the sum of all numbers that can be written as pandigital products.\n")

def isPandigital(n):
    table = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for c in n:
        table[int(c)] += 1
        if table[int(c)] > 1:
            return False
    return True

pandigitalProducts = []
for a in range(1000):
    for b in range(a, 2000):
        c = a * b
        string = str(a)+str(b)+str(c)
        if len(string) < 9: continue
        if len(string) > 9: break
        if isPandigital(string):
            print("%d x %d = %d" %(a, b, c))
            if not c in pandigitalProducts:
                pandigitalProducts.append(c)

print(sum(pandigitalProducts))
