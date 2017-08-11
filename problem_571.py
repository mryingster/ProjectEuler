#!/usr/bin/env python
import itertools

def baseN(n, b, i):
    return ((n == 0) and i[0]) or (baseN(n // b, b, i).lstrip(i[0]) + i[n % b])

def isPan(n, b, i):
    for c in i[0:b]:
        if c not in n:
            return False
    return True

print("Project Euler 571")
print("What is the sum of the 10 smallest 12-super-pandigital numbers?\n")

integers = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B"]
maxBase = 12
sums = []
debug = True

for i in itertools.permutations(integers[:maxBase]):
    # Skip leading zeros
    if i[0] == "0": continue

    # Convert to string
    n = ''.join(map(str, i))

    # Convert to Int (b10)
    n = int(n, maxBase)

    # Check bases
    valid = True
    for b in reversed(range(2, maxBase)):
        # Convert to string of different bases
        base = baseN(n, b, integers)

        # Check for pandigitalness
        pandigital = isPan(base, b, integers)
        if pandigital == False:
            valid = False
            break

    # Record results
    if valid == True:
        sums.append(n)
        if debug == True:
            print(n)

    # Looking for 10
    if len(sums) == 10:
        break

print(sum(sums))

# 30510390701978
# real	57m58.699s
# user	57m59.192s
# sys	0m0.096s
