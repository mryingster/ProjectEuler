#!/usr/bin/env python
import math

print("Project Euler 346:")
print("Find the sum of all strong repunits below 10^12.\n")

limit = 10**12
baseLimit = int(math.sqrt(limit))
binaryLimit = len(bin(limit))
debug = False
repunits = [1]

# Notes about solution:
# Skip 1  - Single digit repunit will always be "1"
#
# Skip 11 - Double digit repunits encapsulate all digits
#           If we find an in-range answer with repunit of 3 (111)
#           or above, it will be the second repunit for that
#           number by definition
#
# Base -    Since we are searching only repunits 3 diguts (111) and
#           above, we can cut our base limit by a factor of 2!

for base in range(2, baseLimit):
    for repeat in range(3, binaryLimit):
        number = 0
        for i in range(repeat):
            number *= base
            number += 1
        if number > limit: break
        if debug == True:
            print("%d, %s, %d" % (base, '1' * repeat, number))
        repunits.append(number)

print(sum(set(repunits)))
