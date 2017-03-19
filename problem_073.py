#!/usr/bin/python

print("Project Euler - Problem 73:")
print("How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d <= 12,000?\n")

upperLimit = 1.0/2.0
lowerLimit = 1.0/3.0

def GetFraction(denominator):
    newFractions = []
    numMin = denominator / 3
    numMax = denominator / 2

    # Find the floating-point values for all fractions within limits
    for i in range(numMin, numMax):
        value=float(i)/float(denominator)
        if value > lowerLimit:
            if value < upperLimit:
                newFractions.append(value)
            else:
                break

    return newFractions

fractionArray=[]
for n in range(2, 12001):
    fractionArray += GetFraction(n)

# Print only the unique (therefore irriducible) values
print(len(list(set(fractionArray))))
