#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_043.swift -o problem_043" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 43:")
print("Find the sum of all 0 to 9 pandigital numbers with the sub-string divisibility property.\n")

func nextPermutation(let a: [Int]) -> [Int] {
    var a = a
    // Find the largest index k such that a[k] < a[k + 1]
    var k = 0
    for i in 0...8 {
        if a[i] < a[i+1] {
            k = i
        }
    }

    // Find the largest index l greater than k such that a[k] < a[l]
    var l = 0
    for i in k...9 {
        if a[k] < a[i] {
            l = i
        }
    }

    // Swap the value of a[k] with that of a[l]
    let t = a[k]
    a[k] = a[l]
    a[l] = t

    // Reverse the sequence from a[k + 1] up to and including the final element a[n]
    if k < 8 {
        var r = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        var j = 9
        for i in (k+1)...9 {
            r[j] = a[i]
            j -= 1
        }
        for i in (k+1)...9 {
            a[i] = r[i]
        }
    }

    return a
}

func subStringDivisible(let a: [Int]) -> Bool {
    let divisor = [0, 2, 3, 5, 7, 11, 13, 17]

    for i in 1...divisor.count-1 {
        let n = a[i] * 100 + a[i+1] * 10 + a[i+2]
        if n % divisor[i] != 0 {
            return false
        }
    }

    return true
}

func arrayToNum(let a: [Int]) -> Int {
    var n = 0
    for i in 0...a.count-1 {
        n *= 10
        n += a[i]
    }
    return n
}

var array: [Int] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
var sum = 0

while array != [9, 8, 7, 6, 5, 4, 3, 2, 1, 0] {
    // Permute
    array = nextPermutation(array)
    // Check for eligibility
    if subStringDivisible(array) {
        // Add!
        sum += arrayToNum(array)
    }
}

print(sum)
