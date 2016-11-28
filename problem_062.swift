#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_062.swift -o problem_062_swift" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

// Deconstruct the number to make a number signature
func numSig(n: Int) -> Int {
    var n = n
    var sig = 0
    while n > 0 {
        sig += Int(pow(10.0, Float(n % 10)))
        n /= 10
    }
    return sig
}

print("Project Euler - Problem 62:")
print("Find the smallest cube for which exactly five permutations of its digits are cube.\n")

let debug = false

// Generate our gonal numbers in the 4 digit range
var cubes = [Int]()
var dict = [Int:[Int]]()
var result = 0

for i in 0...10000 {
    let cube = i * i * i
    let sig = numSig(n: cube)

    // Check if dict contains signature yet
    if let value = dict[sig] {
        // Check if we have already encountered 4 times
        if value[1] == 4 {
            // We found our answer!
            result = value[0]
            break
        }

        // Increment our count
        dict[sig] = [value[0], value[1] + 1]
    } else {
        // If first time encountering sig, record it
        dict[sig] = [i, 1]
    }

    if debug == true {
        print(i, cube, sig)
    }
}

print(result)
