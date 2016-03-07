#!/usr/bin/env python

print("Project Euler - Problem 44:")
print("Find the smallest pair of pentagonal numbers whose sum and difference is pentagonal.\n")

answer = 0
pNumbers = []
for n in range(1, 3000):
    # Find the next pentagonal number, treat this as the SUM of P1 and P2
    sum = n * (3 * n - 1) / 2
    pNumbers.append(sum)

    # Iterate through all lower pentagonal numbers
    for i in range(n-1, 1, -1):
        # Treat this as pentagonal Number 1 (P1)
        p1 = pNumbers[i]

        # Treat difference of sum and P1 as pentagonal Number 2 (P2)
        p2 = sum - p1

        # Treat difference of P1 and P2 as pentagonal Number Difference
        dif = p1 - p2
        if dif < 1: break

        # Make sure all numbers are pentagonal
        if p2 in pNumbers:
            if dif in pNumbers:
                # We have our answer!
                answer = dif
                break
    if answer != 0:
        break

print(answer)
