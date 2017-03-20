#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_073.swift -o problem_073_swift" -*-
// Copyright (c) 2017 Michael Caldwell
import Foundation

struct Fraction {
    var num = 0
    var den = 0
}

print("Project Euler - Problem 73:")
print("How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d <= 12,000?\n\n")

func printFraction(f: Fraction) {
    print(f.num, "/", f.den)
}

func max(n1: Int, n2: Int) -> Int {
    if n1 > n2 { return n1 }
    return n2
}

func reducible(f: Fraction) -> Bool {
    // Filter out 1/2 ratios that get through
    if f.den % f.num == 0 { return true }

    // Set limit of square root of numerator so we don't have to check so many numbers
    let limit = max(n1: Int(sqrt(Float(f.num))), n2: 3)

    for i in 2 ... limit {
        // If numerator is divisible by a number, i, we have two checks to make
        if f.num % i == 0 {
            // If we can also divide denominator by i, it's reducible
            if f.den % i == 0 { return true }

            // If we can divide denominator by result of numerator / i, it's reducible
            if f.num != i && f.den % (f.num / i) == 0 { return true }
        }
    }
    return false
}

let limit = 12000 // Denominator limit
let debug = false
var count = 0

for denominator in 5 ... limit {
    // Find numerator limits
    let min = denominator / 3 + 1
    let max = denominator / 2

    // Test each numerator between the limits
    for numerator in min ... max {
        let fraction = Fraction(num: numerator, den: denominator)
        if reducible(f: fraction) == false {
            if debug == true { printFraction(f: fraction) }
            count += 1
        }
    }
}

print(count)

