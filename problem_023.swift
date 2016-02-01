#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_023.swift -o problem_023" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 23:")
print("Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.\n")

func divisorSum(n:Int) -> Int {
    var s = 0
    for d in 1...n/2+1 {
        if n % d == 0 {
            s += d
        }
    }
    return s
}

let limit = 28123
var abundant: [Int] = []

for var n in 12...limit {
    if divisorSum(n) > n {
        abundant.append(n)
    }
}

var abundantSum = [Bool](count: limit, repeatedValue: false)
for var a in 0...abundant.count-1 {
    for var b in 0...abundant.count-1 {
        var n = abundant[a] + abundant[b]
        if n >= limit {
            break
        }
        abundantSum[n] = true
    }
}

var sum = 0
for var n in 0...limit-1 {
    if abundantSum[n] == false {
        sum += n
    }
}

print(sum)
