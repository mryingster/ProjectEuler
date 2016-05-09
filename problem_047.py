#!/usr/bin/env python

print("Project Euler - Problem 47:")
print("What is the first of four consecutive integers to have four distinct prime factors?\n")

limit = 500000
primeSieve = [0] * (limit)
answer = 4

# Find primes using sieve
for n in range(2, limit):
    if primeSieve[n] == 0:
        m = 2
        while m * n < limit:
            primeSieve[m * n] += 1
            m += 1

    if primeSieve[n] == 4:
        answer -= 1
        if answer == 0:
            answer = n-3
            break
    else:
        answer = 4

print(answer)

