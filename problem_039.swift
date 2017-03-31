#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_039.swift -o problem_039" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 39:")
print("Find the perimeter of a right triangle (p) that has the most possible solutions, where the perimiter is less than or equal to 1000.\n")

let limit = 1000
var results = [Int](repeating: 0, count: limit + 1)

for a in 1 ... limit {
    for b in a ... limit {
        let c_float :Double = sqrt(Double((a * a) + (b * b)))
        let c = Int(c_float)

        // Make sure result is integer
        if Double(c) != c_float {
            continue
        }

        // Make sure not more than limit
        let p = a + b + c
        if p > limit {
            continue
        }

        // Track results
        results[p] += 1
    }
}

var max = 0
for i in 0 ..< results.count {
    if results[i] > results[max] {
        max = i
    }
}

print(max)
