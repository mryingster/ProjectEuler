#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_069.swift -o problem_069_swift" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

print("Project Euler - Problem 69:")
print("Find the value of n <= 1,000,000 for which n/phi(n) is a maximum, where phi(n) is Euler's Totient function.\n")

var limit = 1000000;
var n = 1;
var primes = [Int](repeating: 1, count: 1000)

for i in 2 ..< primes.count {
    // Find primes and multiply them together
    if primes[i] == 1 {
        // Stop if we exceed our limit
        if n * i >= limit {
            break
        } else {
            n *= i
        }

        // Sieve to find next prime
        var m = 1
        while m * i < primes.count {
            primes[m*i] = 0
            m += 1
        }
    }
}

print(n)
