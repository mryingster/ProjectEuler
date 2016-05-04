#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_055.swift -o problem_055" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 55:")
print("How many Lychrel numbers are there below ten-thousand?\n")

func reverse(n:UInt64) -> UInt64 {
    var n = n
    var r: UInt64 = 0

    while n > 0 {
        r *= 10
        r += n % 10
        n /= 10
    }

    return r
}

var total = 0

for i in 10...10000 {
    var lychrel = true
    var n: UInt64 = UInt64(i)

    // Assume lychrel if not palindromic ater 50 reversals
    for t in 1...50 {
        n += reverse(n)

        // Going to go as far as we can with 64 bit ints
        // Turns out that is accurate enough for solution
        if n > UInt64(INT64_MAX) {
            break
        }

        if reverse(n) == n {
            lychrel = false
            break
        }
    }

    if lychrel == true {
        total += 1
    }
}

print(total)
