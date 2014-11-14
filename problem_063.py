#!/usr/bin/python

print("Project Euler - Problem 63:")
print("How many n-digit positive integers exist which are also an nth power?\n")

total=0
for i in range(1, 100):
    for n in range(1, 100):
        result=i**n
        if len(str(result)) == n:
            #print str(i)+"^"+str(n)+"="+str(result) # DEBUG
            total += 1

print("Total n-digit integers: "+str(total))
