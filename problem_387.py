#!/usr/bin/env python
import math

def isPrime(input):
    if input < 2: return False;
    if input == 2: return True;
    if input % 2 == 0: return False;

    for index in xrange (3, int(math.sqrt(input))+1, 2):
      if input % index == 0:
          return False

    return True

def sumDigits(n):
    sum = 0
    while n > 0:
        sum += n % 10
        n /= 10
    return sum

print("Project Euler - Problem 387:")
print("Find the sum of the strong, right truncatable Harshad primes less than 10^14\n")

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
harshad = []
limit = 10**14

for i in range(12):
    new = []
    candidate = []

    # Build harshad numbers that are right-truncatable
    for a in numbers:
        for b in range(10):
            t = int(str(a) + str(b))

            # Sum their digits
            digits = sumDigits(t)

            # Only continue building ones that are divisible by their sums
            if t % digits == 0:
                new.append(t)

                # If the division is prime, it is strong
                # save to check if Harshad Prime
                if isPrime(t/digits) :
                    candidate.append(t)

    # Store eligible numbers for the next loop
    numbers = new

    # Look through candidates to see if they are Harshad Primes
    for a in candidate:
        for b in range(10):
            # Add a digit to the right
            t = int(str(a) + str(b))
            # Make sure its not longer than limit
            if t < limit:
                # Check to see if it is prime
                if isPrime(t):
                    # Add it to our list
                    harshad.append(t)

# Sum all of the right-truncatable Harshad prime numbers
print sum(harshad)
