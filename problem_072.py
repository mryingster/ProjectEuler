#!/usr/bin/env python

print("Project Euler - Problem 72:")
print("How many elements would be contained in the set of reduced proper fractions for d <= 1,000,000?\n")

MaxValue = 1000001;
count = 0;
phi = [0] * 1000001;

# Give each element initial value
for i in range(MaxValue):
    phi[i] = i

# Perform eulers totient function
for n in range(2, MaxValue):
    if phi[n] == n:
        k = n
        while k < MaxValue:
            phi[k] *= (n - 1.0) / n
            k += n

# Print/tabulate results
for i in range(MaxValue):
    count += phi[i];

print("Number of unique fractions: %d" % (count-1))
