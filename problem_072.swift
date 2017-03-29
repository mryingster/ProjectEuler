#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_072.swift -o problem_072_swift" -*-
// Copyright (c) 2017 Michael Caldwell
import Foundation

print("Project Euler - Problem 72:")
print("How many elements would be contained in the set of reduced proper fractions for d <= 1,000,000?\n")

var phi = [Int](repeating: 0, count: 1000001)
let max_value = phi.count

// Initialize Array
for i in 0 ..< max_value {
    phi[i] = i
}

// Perform Euler's Totient
for n in 2 ..< max_value {
    // If value hasn't been calculated yet, it the next prime we will use
    if phi[n] == n {
        // For totient, multiply each number by 1 - 1/p for each prime factor
        var k = n
        while k < max_value {
            //print(n, phi[n], k, phi[k])
            phi[k] = phi[k] / n * (n - 1)
            k += n
        }
    }
}

// tabulate results
var count = 0
for i in 2 ..< max_value {
    count += phi[i]
}

print(count)
