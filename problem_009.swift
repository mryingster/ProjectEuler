#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_009.swift -o problem_009" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 9:")
print("There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.\n")

let limit = 1000
var product = 0
for a in 1...limit {
    for b in a...limit {
        var c: Double = sqrt(Double((a * a) + (b * b)))

        var sum = a+b+Int(c)
        if sum > limit { break }

        if floor(c) == c && sum == limit {
            product = a * b * Int(c)
        }
        if product != 0 { break }
    }
    if product != 0 { break }
}

print(product)
