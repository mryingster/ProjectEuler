#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_071.swift -o problem_071_swift" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

print("Project Euler - Problem 71:")
print("By listing the set of reduced proper fractions for d <= 1,000,000 in ascending order of size, find the numerator of the fraction immediately to the left of 3/7.\n")

let limit = 1000000
let targetNumerator = 3.0
let targetDenominator = 7.0

var closestNumerator = 0
var closestDouble = 0.0

for denominator in 7 ... limit {
    let numerator = Int(Double(denominator) / targetDenominator * targetNumerator - 1.0)
    let fraction = Double(numerator) / Double(denominator)
    if fraction > closestDouble {
        closestDouble = fraction
        closestNumerator = numerator
    }
}

print(closestNumerator)
