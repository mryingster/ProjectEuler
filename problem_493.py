#!/usr/bin/env python

def factorial(n):
    f = 1
    while n > 0:
        f *= n
        n -= 1
    return f

def choose(n, k):
    num = factorial(n)
    den = factorial(k) * factorial(n-k)
    return num/den

print("Project Euler  - Problem 491:")
print("70 colored balls are placed in an urn, 10 for each of the seven rainbow colors. What is the expected number of distinct colors in 20 randomly picked balls rounded to 10 digits?\n")

numberOfColors = 7
ballsPerColor = 10
numberOfBalls = numberOfColors * ballsPerColor
ballsPicked = 20

waysOfMissingColor = float(choose(numberOfBalls - ballsPerColor, ballsPicked))
allWaysOfSelecting = float(choose(numberOfBalls, ballsPicked))
probabilityOfMissingSingleColor = waysOfMissingColor / allWaysOfSelecting
probabilityOfDistinctColors = 7 * (1 - probabilityOfMissingSingleColor)

print("%1.9f" % probabilityOfDistinctColors)
