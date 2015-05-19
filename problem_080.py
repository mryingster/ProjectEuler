#!/usr/bin/env python

print("Project Euler - Problem 80:")
print("For the first one hundred natural numbers, find the total of the digital sums of the first one hundred decimal digits for all the irrational square roots.\n")

def sqroot(a, digits):
    a = a * (10**(2*digits))
    x_prev = 0
    x_next = 1 * (10**digits)
    while x_prev != x_next:
        x_prev = x_next
        x_next = (x_prev + (a // x_prev)) >> 1
    return x_next

debug = False
sum = 0

for n in range(2, 100):
    # Skip perfect numbers
    if float(n**(1.0/2.0)) == int(float(n**(1.0/2.0))):
        if debug == True: print("Skipping "+str(n)) # DEBUG
        continue;

    # Get the square root to 99 digits
    root = str(sqroot(n, 99))

    # Sum all of the digits
    for i in range(len(root)):
        sum += int(root[i])

print("Sum: "+str(sum))
