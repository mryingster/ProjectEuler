#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_039.swift -o problem_039" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 39:")
print("Find the perimeter of a right triangle (p) that has the most possible solutions, where the perimiter is less than or equal to 1000.\n")

var perimeter = [Int](count: 1001, repeatedValue: 0)
var max = 0

for a in 1...1000 {
    for b in a...1000 {
        let cFloat = sqrt(Float((a*a) + (b*b)))
        let cInt = Int(cFloat)
        if cFloat != Float(cInt) { continue }
        let sum = a + b + cInt
        if sum > 1000 { continue }
        perimeter[sum] += 1
        if perimeter[sum] > perimeter[max] {
            max = sum
        }
    }
}

print(max)
