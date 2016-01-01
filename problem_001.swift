#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_001.swift -o problem_001" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 1:")
print("Find the sum of all the multiples of 3 or 5 below 1000.\n")

var total = 0
let limit = 1000

for n in 0...limit {
    if n % 3 == 0 || n % 5 == 0 {
        total += n
    }
}

print(total)
