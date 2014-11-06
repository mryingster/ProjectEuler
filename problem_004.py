#!/usr/bin/env python

print("Project Euler - Problem 4:")
print("Find the largest palindrome made from the product of two 3-digit numbers.\n")

result = 0

for a in range(100, 999):
    for b in range(100, 999):
        product = a * b
        tcudorp = 0
        while (product > 0):
            tcudorp = int(tcudorp * 10)
            tcudorp +=   (product % 10)
            product = int(product / 10)
        product = a * b
        #print (product, tcudorp) #DEBUG
        if ( product == tcudorp ):
            if result < product:
                result = product

print("Largest product: "+str(result))
