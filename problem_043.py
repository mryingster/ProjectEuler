#!/usr/bin/env python
import re

print("Project Euler - Problem 43:")
print("Find the sum of all 0 to 9 pandigital numbers with the sub-string divisibility property.\n")

def permute(num):
    length = len(num)
    used = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]       # Array to store numbers in!
    used[int(num[length-1])] = 1                # Prime array
    for i in range(length-2, -1, -1):           # Start at right and move left
        used[int(num[i])] += 1                  # Keep track of digits encountered
        if int(num[i]) < int(num[i+1]):         # Look for first digit that is smaller than digit to right
            newNum = str(num[:i])               # New number is everything to left of digit encountered

            for n in range(int(num[i])+1, 10):  # Look for next biggest number in used array
                if used[n] > 0:                 # If array contains an available number
                    used[n] -= 1                # Take one out
                    newNum += str(n)            # Append it to our new number string
                    break                       # Get out of here!

            for n in range(0, 10):              # Now go through the used array (smallest first)
                while used[n] > 0:              # If we have available digits
                    used[n] -= 1                # Take out out
                    newNum += str(n)            # Append it to out new number string

            return newNum                       # Return the number

def subStringy(n):
    primes = [2, 3, 5, 7, 11, 13, 17]
    for i in range(7):
        if int(n[1+i:i+4]) % primes[i] != 0: return False
    return True

n = "1406357289"
sum = 0
while n[0] < "9":
    if subStringy(n) == True:
        sum += int(n)
    n = permute(n)

print(sum)
