#!/usr/bin/env python

print("Project Euler - Problem 33:")
print("Find the denominator of the product of all the two digit fractions with a non-trivial unorthodox canceling method.\n")

debug = False

#Find non-trivial, unorthodox canceling fractions
result=[1,1]
for num in range(11, 100):
    for den in range(num, 100):
        n=str(num)
        d=str(den)
        if n[1] == d[0] and n[1] != d[1] and d[1] != "0":
            if (1.0*num)/(1.0*den) == (1.0*int(n[0]))/(1.0*int(d[1])):
                result[0] *= num
                result[1] *= den
                if debug == True: print("Found: %d/%d" %(num, den))

# Simplify result
if debug == True: print("Fraction: %d/%d" % (result[0], result[1]))
t = 2
while t <= result[0]:
    if result[0] % t == 0 and result[1] % t == 0:
        result[0] /= t
        result[1] /= t
    else:
        t += 1
if debug == True: print("Reduced Fraction: %d/%d" % (result[0], result[1]))

# Print simplified denominator
print(result[1])
