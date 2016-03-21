#!/usr/bin/env python
import re

print("Project Euler - Problem 51:")
print("Find the smallest prime which, by replacing part of the number with the same digit, is part of an eight prime value family.\n")

limit = 1000000
primes = [0, 0] + [1] * (limit-2)
smallest = 0

for i in range(len(primes)):
    # If we find a prime
    if primes[i] == 1:
        # And it has more than 3 9's
        if str(i).count('9') >= 3:
            count = 0
            # Try replacing the 9's with other digits
            for n in range(9, 0, -1):
                temp = re.sub("9", str(n), str(i))
                # And see if they are also prime
                if primes[int(temp)] == 1:
                    count += 1
                    # If we find 8 additional primes this way
                    if count > 7:
                        # We have our solution!
                        smallest = temp

        # Seive
        n = 2
        while n * i < limit:
            primes[n * i] = 0
            n += 1

    # Break out if we found an answer!
    if smallest != 0: break

print(smallest)
