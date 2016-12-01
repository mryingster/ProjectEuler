#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_063.swift -o problem_063_swift" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

print("Project Euler - Problem 63:")
print("How many n-digit positive integers exist which are also an nth power?\n")

let debug = false
var total = 0

for n in 1...100 {
    for e in 1...100 {
        let number = pow(Float(n), Float(e))
        let length = floor(log10(number)) + 1.0

        // Check if length is equal to exponent
        if length == Float(e) {
            total += 1
        }

        // Break if length greater than exponent
        if length > Float(e) {
            break
        }

        if debug == true {
            print(n, e, number, length)
        }
    }
}

print(total)
