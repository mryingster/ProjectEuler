#!/usr/bin/python

def calcRemainder(a, n):
    result=((a-1)**n+(a+1)**n)%a**2
    return result

print("Project Euler 120:")
print("For 3 <= a <= 1000, find the sum of r max where r is the remainder when (a-1)^n + (a+1)^n is divided by a^2\n")

sum = 0
end = 1001
cycle = 1
debug = False

n = 1
for a in range(3, end):
    if cycle == 1:
        n=1+(int(a/4) * 2)
    if cycle == 3:
        n=1+(int(a/4) * 6)
    if cycle == 4:
        n=1+(int(a/4) * 4)
        cycle=0

    value = calcRemainder(a, n)
    sum += value

    if debug == True:
        print(a, value)

    cycle+=1

print(sum)
