#!/usr/bin/env python

print("Project Euler - Problem 14:")
print("Which starting number, under one million, produces the longest chain by following the rules below?\n")
print("if n is even, n/2")
print("if n is odd, 3n+1\n")

history = [0, 1]
for i in range(2, 1000000):
    chain = 0
    n = i
    while n != 1:
        chain += 1

        # We've been here before. Shortcut!
        if n < i:
            if history[n] == -1:
                chain = -1
            else:
                chain += history[n]
            break

        if n % 2 == 0:
            n /= 2
        else:
            n = n * 3 + 1

        # Oh no! We are stuck!
        if n == i:
            chain =-1
            break

    history.append(chain)

max = [0, 0]
for n in range(len(history)):
    if history[n] > max[1]:
        max[0] = n
        max[1] = history[n]

print("%d (length: %d)" % (max[0], max[1]))
