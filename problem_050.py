#!/usr/bin/env python

print("Project Euler - Problem 50:")
print("Which prime, below one-million, can be written as the sum of the most consecutive primes?\n")

limit = 1000000
primeSieve = [0, 0] + [1] * (limit-2)
primes = []
debug = False

# Find primes using sieve
for n in range(len(primeSieve)):
    if primeSieve[n] == 1:
        primes.append(n)
        m = 2
        while m * n < limit:
            primeSieve[m * n] = 0
            m += 1

answer = [0, 0, 0, 0] # number, count, prime, base
count = 0             # How many steps of primes
base = 0              # Index of prime that we are starting on
n = 0                 # Current value of our number
p = 0                 # Prime we are adding for this step
while p < range(len(primes)):
    #print n, p, count, "(best:", answer[0], ")"
    n += primes[p]
    count += 1

    # Look for new best candidates with highest count
    if n in primes and answer[1] < count:
        if debug == True: print("New winner!", n, count)
        answer = [n, count, p, base]

    # Reset to last good configuration, then subtract
    # prime we started with and try to build again
    if n > limit:
        n = answer[0]
        count = answer[1]
        count -= 1
        p = answer[2]
        n -= primes[base]
        base += 1

    # Increment our prime number for the next step
    p += 1

    # If we have started with every prime < 100, that's probably enough
    if base > 100: break

if debug == True:
    print("")
    print("Final answer:", answer[0])
    print("Starting number:", primes[answer[3]])
    print("Number of steps:", answer[1])
    print("Final prime:", primes[answer[2]])

print(answer[0])
