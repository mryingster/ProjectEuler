#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_026.swift -o problem_026" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 26:")
print("Find the value of d < 1000 for which 1/d contains the longest recurring cycle.\n")

var longest = [0, 0]
let debug = false

for d in 2...1000 {
    var answer = [1]
    var repeatIndex = 1
    var repeatLength = -1
    var i = 0

    // Perform long division!
    while answer.count < 1500 {
        var tmp1 = answer[i] / d
        var tmp2 = tmp1 * d
        answer[i] -= tmp2
        answer.append(0)
        if answer[i] < d {
            answer[i+1] += answer[i]*10
            answer[i] = 0
        }
        answer[i] = tmp1

        // Keep track if repeating digits.
        if answer.count > 3 {
            if answer[i] == answer[repeatIndex] {
                repeatIndex += 1
            } else {
                repeatIndex = 1
            }
        }
        if repeatIndex >= 10 {
            repeatLength = i - repeatIndex + 1
            if repeatLength > longest[0] {
                longest[0] = repeatLength
                longest[1] = d
            }
            break
        }
        i += 1
    }

    // Print answers
    if debug == true {
        print(String(format:"1/%d repeats after %d digits", d, repeatLength))
        print(answer)
    }
}

print(longest[1])
