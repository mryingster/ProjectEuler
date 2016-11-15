#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_057.swift -o problem_057_swift" -*-
// Copyright (c) 2016 Michael Caldwell

func carry(a: [Int]) -> [Int] {
    var a = a
    for i in 0...a.count-1 {
        while a[i] > 9 {
            a[i] -= 10
            a[i+1] += 1
        }
    }
    return a
}

print("Project Euler - Problem 57:")
print("In the first one-thousand expansions of 1+1/(2+1/(2+1/(2+...)))=1.414213, how many fractions contain a numerator with more digits than denominator?\n")

let debug = false
let max = 1000

// Setup our big number holders
var num = [Int](repeating: 0, count: max)
var num_old = [Int](repeating: 0, count: max)
var num_older = [Int](repeating: 0, count: max)
var den = [Int](repeating: 0, count: max)

num[0] = 3
num_old[0] = 1
num_older[0] = 3
den[0] = 2

var topheavy = 0

for _ in 0...max {
    // Update numbers
    for i in 0...num.count-1 {
        den[i] += num[i]
        num_older[i] = num_old[i]
        num_old[i] = num[i]
        num[i] = num[i] * 2 + num_older[i]
    }

    // Carry over values
    num = carry(a: num)
    den = carry(a: den)

    // Count digits
    var num_count = max-1
    var den_count = max-1
    while num[num_count] == 0 { num_count -= 1 }
    while den[den_count] == 0 { den_count -= 1 }

    // Check if topheavy
    if num_count > den_count {
        topheavy += 1
    }

    // DEBUG - Print Fractions
    if debug == true {
        for i in (0...num_count).reversed() { print(num[i], terminator:"") }
        print(" / ", terminator:"")
        for i in (0...num_count).reversed() { print(den[i], terminator:"") }
        print(" : ", num_count, " digits / ", den_count, " digits")
    }
}

print(topheavy)
