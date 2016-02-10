#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_024.swift -o problem_024" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 24:")
print("Find the 1,000,000th lexiconic permutation of the numbers 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.\n")

func nextPermutation(var a: [Int]) -> [Int] {
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

var number: [Int] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
var count = 0

while count < 1000000 {
    number = nextPermutation(number)
    count += 1
    //print(number, count)
}

for i in 0...9 {
    print(number[i], terminator: "")
}
print("")
