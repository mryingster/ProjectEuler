#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_037.swift -o problem_037" -*-
// Copyright (c) 2016 Michael Caldwell
import Darwin

print("Project Euler - Problem 37:")
print("Find the sum of the only eleven primes that are both truncatable from left to right and right to left.\n")

var primeSieve = [Int](count: 1000000, repeatedValue: 1)
primeSieve[0] = 0
primeSieve[1] = 0

var primes:[Int] = []

// Get our primes!
for n in 2...999999 {
    if primeSieve[n] == 1 {
        primes.append(n)
        for var i=2; i*n < primeSieve.count; i++ {
            primeSieve[n*i] = 0
        }
    }
}

var count = 11
var sum = 0

for n in primes {
    if n < 10 {
        continue
    }

    var truncatable = true

    // Check truncatable right
    var t = n / 10
    var tcount = 0
    while t > 0 && truncatable == true {
        if primeSieve[t] == 0 {
            truncatable = false
        }
        tcount += 1
        t /= 10
    }

    // Check truncatable left
    t = n
    while tcount > 0 && truncatable == true  {
        t = t % Int(pow(10, (Float(tcount))))
        tcount -= 1
        if primeSieve[t] == 0 {
            truncatable = false
        }
    }

    // Add it all up!
    if truncatable == true {
        sum += n
        count -= 1
    }

    if count == 0 {
        break
    }
}

print(sum)
