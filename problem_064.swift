#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_064.swift -o problem_064_swift" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

print("Project Euler - Problem 64:")
print("How many continued fractions for N <= 10000 have an odd period?\n")

var number = 0
var count = 0
let debug = false

while number < 10000 {
    number += 1
    let a0 = Int(sqrt(Float(number)))

    // Check if perfect square; skip
    if a0 * a0 == number {
        continue
    }

    var period = 0
    var d = 1
    var m = 0
    var a = a0

    while a != a0 * 2 {
        m = d * a - m
        d = (number - (m * m)) / d
        a = (a0 + m) / d
        period += 1
    }


    if period % 2 != 0 {
        count += 1
    }

    if debug == true {
        print(number, period)
    }
}

print(count)
