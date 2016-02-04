#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_030.swift -o problem_030" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 30:")
print("Find the sum of all the numbers that can be written as the sum of fifth powers of their digits\n")

func powerDigitSum(var n:Int) -> Int {
    var sum = 0
    while n > 0 {
        let d = n % 10
        n /= 10
        sum += Int(pow(Double(d), Double(5)))
    }
    return sum
}

var sum = 0

for i in 10...355000 {
    if i == powerDigitSum(i) {
        sum += i
    }
}

print(sum)
