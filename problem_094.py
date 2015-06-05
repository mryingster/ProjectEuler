#!/usr/bin/env python
import math

print("Project Euler - Problem 94")
print("Find the sum of the perimeters of all almost equilateral triangles with integral side lengths and area and whose peimeters do not exceeen one billion.\n")

a     = 2
Lasta = 1
b     = 0
Perimeter    = 0
PerimeterSum = 0
skip  = math.tan(5*math.pi/12)
debug = False

# A = Hypotinuse
# B = Short side, gets halved
# C = New leg

def FindC(A, B):
    B = B / 2.0
    C = ( A**2. - B**2.)**(1./2)
    if C == int(C):
        return C
    else:
        return 0

while 1:
    for b in (a-1, a+1):
        Perimeter = a + a + b
        if FindC(a, b) != 0:
            PerimeterSum += Perimeter
            if debug == True:
                print("A=%-11d B=%-11d C=%-11d P=%-11d T=%-11d x=%f" % (a, a, b, Perimeter, PerimeterSum, (a*1.0)/(Lasta*1.0)))
            Lasta = a
            # Guess next position to get close to next number
            a = int(a * skip) - 10

    a += 1
    if Perimeter > 1000000000: break

print(PerimeterSum)
