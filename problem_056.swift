#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_056.swift -o problem_056_swift" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 56:")
print("Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?\n")

var max = 0

for b in 1...100 {
    var digits = [Int](count: 200, repeatedValue: 0)
    digits[0] = b

    for _ in 1...100 {
        var sum = 0

        // Multiply each digit by the base num
        for i in 0...digits.count-1 {
            digits[i] *= b

            // Carry over multiplication
            if i > 0 {
                while digits[i-1] > 9 {
                    digits[i-1] -= 10
                    digits[i] += 1
                }

                // Sum the digits
                sum += digits[i-1]
            }
        }

        // See if new max
        if sum > max {
            max = sum
        }
    }
}

print(max)
