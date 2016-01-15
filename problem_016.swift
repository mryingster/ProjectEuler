#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_016.swift -o problem_016" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 16:")
print("What is the sum of the digits of the number 2^1000\n")

var num: [Int] = [2]
var debug: Bool = false

for i in 1...999 {
    for n in 0...num.count-1 {
        num[n] *= 2
    }

    for n in 0...num.count-1 {
        while num[n] > 9 {
            num[n] -= 10
            if n == num.count-1 {
                num.append(0)
            }
            num[n+1] += 1
        }
    }
}

var sum = 0
for var n = num.count-1; n >= 0 ; n-- {
    sum += num[n]
    if debug == true {
        print(num[n], terminator: "")
    }
}

print("")
print(sum)
