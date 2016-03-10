#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_046.swift -o problem_046" -*-
// Copyright (c) 2016 Michael Caldwell
import Darwin

print("Project Euler - Problem 46:")
print("What is the smallest odd, composite number that cannot be written as the sum of a prime and twice a square?\n")

var primeSieve = [Int](count: 1000000, repeatedValue: 1)
primeSieve[0] = 0
primeSieve[1] = 0
var answer = 0

// Get our primes!
for n in 2...999999 {
    // -1 and odd == Answer
    if primeSieve[n] == -1 && n % 2 != 0 {
        answer = n
        break
    }

    // Positive == Prime
    if primeSieve[n] > 0 {
        // Mark multiples as non-prime (negative)
        for var i=2; i*n < primeSieve.count; i++ {
            if primeSieve[n*i] > 0 {
                primeSieve[n*i] *= -1
            }
        }

        // +/- 2 == product of prime and double a square
        for var i=1; 2 * i * i + n < primeSieve.count; i++ {
            let t = 2 * i * i + n
            if primeSieve[t] == -1 {
                primeSieve[t] = -2
            }
            if primeSieve[t] == 1 {
                primeSieve[t] = 2
            }
        }
    }
}

print(answer)
