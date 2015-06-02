#!/usr/bin/env python
from fractions import gcd

print("Project Euler - Problem 91")
print("Given that 0 <= x1, y1, x2, y2, <= 50, how many right triangles can be formed?\n")

length = 50
count  = 0
debug  = False

# Standard Triangles where the right angle is at 0,0
for x in range(1, length+1):
    for y in range(1, length+1):
        count += 3
        if debug == True:
            print("a=0,0  b= 0,%2d  c=%2d, 0  (x3)  count=%d" % (x, y, count))

for y in range(1, length+1):
    for x in range(1, length+1):
        # Get slope from origin to point
        xygcd    = gcd(x, y)
        reducedx = x / xygcd
        reducedy = y / xygcd

        # Project slope to lower left at 90 degrees, look for integer location within bounds
        xprime = x + reducedy
        yprime = y - reducedx
        while xprime <= length and yprime >= 0:
            # Add two to counter since each triangle can be mirrored
            count += 2
            if debug == True:
                print("a=0,0  b=%2d,%2d  c=%2d,%2d  (x2)  count=%d" % (x, y, xprime, yprime, count))
            xprime += reducedy
            yprime -= reducedx

print("%d" % count)
