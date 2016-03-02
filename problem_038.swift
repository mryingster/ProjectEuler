#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_038.swift -o problem_038" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 38:")
print("What is the largest 1 to 9 pandigital that can be formed by multiplying a fixed number by 1, 2, 3, ... ?\n")

func numberOfDigits(var n: Int) -> Int {
    if n == 0 { return 1 }
    if n <  0 { n = n * -1 }
    return Int(floor(log10(Float(n)))) + 1
}

func isPandigital(var n: Int) -> Bool {
    var digit = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    while n > 0 {
        let d = n % 10
        n /= 10
        if digit[d] == 1 {
            return false
        }
        digit[d] = 1
    }
    return true
}

var largest = 0

for b in 1...10000 {
    var n = 0
    var m = 0
    while numberOfDigits(n) < 9 {
        m += 1
        var t = b * m
        n = n * Int(pow(10.0, Float(numberOfDigits(t))))
        n += t
    }
    if numberOfDigits(n) == 9 {
        if isPandigital(n) == true {
            if n > largest {
                largest = n
            }
        }
    }
}


print(largest)
