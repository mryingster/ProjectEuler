#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_034.swift -o problem_034" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 34:")
print("Find the sum of all numbers which are equal to the sum of the factorial of their digits.\n")

var factorial = [1]
for i in 1...9 {
    factorial.append(i * factorial[i-1])
}

var sum = 0
for i in 10...1000000 {
    var nSum = 0
    var n = i
    while n > 0 {
        nSum += factorial[n%10]
        n /= 10
    }

    if nSum == i {
        sum += i
    }
}

print(sum)

