#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_052.swift -o problem_052" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 52:")
print("Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.\n")

func numSig(n:Int) -> Int {
    var n = n
    var sig = 0
    while n > 0 {
        sig += Int(pow(10.0, Float(n) % 10))
        n /= 10
    }
    return sig
}

var solution = 0
for i in 1000...1000000 {
    var aSig = numSig(i)
    solution = i
    for m in 2...6 {
        if numSig(m*i) != aSig {
            solution = 0
            break
        }
    }

    if solution != 0 {
        break
    }
}

print(solution)
