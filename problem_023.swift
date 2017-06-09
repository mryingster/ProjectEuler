#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_023.swift -o problem_023 -O" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 23:")
print("Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.\n")

let limit = 28123
var divisorSums = [Int](repeating: 1, count: limit + 1)
var abundantNumbers: [Int] = []

for var n in 2...limit {
    if divisorSums[n] > n {
        abundantNumbers.append(n)
    }

    for var m in stride(from:n, to:limit, by:n) {
        divisorSums[m] += n
    }
}

var abundantSum = [Bool](repeating: false, count: limit)
for var a in abundantNumbers {
    for var b in abundantNumbers {
        if b < a { continue }
        var n = a + b
        if n >= limit { break }
        abundantSum[n] = true
    }
}

var sum = 0
for var n in 0..<limit {
    if abundantSum[n] == false {
        sum += n
    }
}

print(sum)
