#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_028.swift -o problem_028" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 28:")
print("Starting with the number 1 and moving to the right in a clockwise direction, form a 1001 by 1001 spiral. What is the sum of the numbers on the diagonals in this spiral?\n")

var sum = 1
var skip = 2
var step = skip
var side = 1

for n in 1...1001*1001 {
    if side == 4 {
        skip += 2
        side = 0
    }

    if step == 0 {
        sum += n
        side += 1
        step = skip
    }

    step -= 1
}

print(sum)
