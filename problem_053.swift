#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_053.swift -o problem_053" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 53:")
print("How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?\n")

func qualifies(n:Int, r:Int) -> Bool {
    var n = n
    let limit = 1000000
    var nr = n-r
    var answer = 1

    while n > r {
        answer *= n
        while nr > 1 && (answer % nr == 0 || answer > limit) {
            answer /= nr
            nr -= 1
        }

        if nr <= 1 && answer > limit {
            return true
        }

        n -= 1
    }

    return false
}

var total = 0

for n in 23...100 {
    for r in 1...n {
        if qualifies(n, r: r) == true {
            total += 1
        }
    }

}

print(total)
