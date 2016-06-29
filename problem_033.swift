#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_033.swift -o problem_033" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 33:")
print("Find the product of all the two digit fractions with an unorthodox canceling method.\n")

func reduce(let f: [Int]) -> [Int] {
    var f = f
    var d = 2

    while d <= f[0] {
        while f[0] % d == 0 && f[1] % d == 0 {
            f[0] /= d
            f[1] /= d
        }
        d += 1
    }

    return f
}

func unorthodox(let f: [Int]) -> Bool {
    // Numerator 2nd digit == denominator 1st digit
    if f[0] % 10 == f[1] / 10 {

        // Cancel unorthodoxly
        let c = [f[0] / 10, f[1] % 10]

        // See if fractions are the same by reducing them both
        if reduce(f) == reduce(c) {
            //print(f[0], "/" ,f[1], " = ", c[0], "/", c[1])
            return true
        }
    }

    return false
}

var total = [1, 1]
for den in 10...100 {
    for num in 10...den {
        if unorthodox([num, den]) {
            total[0] *= num
            total[1] *= den
            total = reduce(total)
        }
    }
}

print(total[1])

