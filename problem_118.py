#!/usr/bin/env python
import math, array

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

            for n in range(1, 10):              # Now go through the used array (smallest first)
                while used[n] > 0:              # If we have available digits
                    used[n] -= 1                # Take out out
                    newNum += str(n)            # Append it to out new number string

            return int(newNum)                  # Return the number

def isPrime(n):
    if n < 2: return False
    if n == 2: return True
    if n % 2 == 0: return False
    lim = int(math.sqrt(n))+1
    for i in range(3, lim, 2):
      if n % i == 0:
          return False
    return True;

def recurse(num, prev, count):
    l = len(str(num))                                   # Get number of digits
    i = 1                                               # Start with only first digit
    while i <= l:
        leftTrunc = int(str(num)[:i])                   # Truncate from left, 1 at a time
        if isPrime(leftTrunc) and leftTrunc > prev:     # If truncation is prime and ordered
            if i == l:                                  # If truncation is also remainder of num
                return count+1                          # Set found. Increment count!
            newTrunc = int(str(num)[i:])                # Get rest of number,
            count = recurse(newTrunc, leftTrunc, count) # And feed it back into recurse
        i += 1                                          # Increase size of truncation by 1
    return count

print("Project Euler - Problem 118:")
print("How many distinct sets containing each of the digits one through nine exactly once contain only prime elements?\n")

debug = False
num = 123456789 # Smallest pandigital
count = 0

while num != None:
    pcount = count
    count = recurse(num, 0, count)
    if debug == True:
        if pcount != count:
            print("n=%d Sets: %d Total: %d" % (num, count-pcount, count))
    num = permute(str(num))

print("Distinct Sets: %d" % count)
