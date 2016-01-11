#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_015.swift -o problem_015" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 15:")
print("Starting in the top left corner in a 20 by 20 grid, how many routes are there to the bottom right corner?\n")

var triangle: [[Int]] = [[1, 0], [1, 1, 0]]
var debug: Bool = false

for i in 2...40 {
    triangle.append([1])
    for n in 1...i {
        triangle[i].append(triangle[i-1][n-1] + triangle[i-1][n])
    }
    triangle[i].append(0)
}

// Debug print
if debug == true {
    for i in 0...triangle.count - 1 {
        for n in 0...triangle[i].count - 1 {
            print(triangle[i][n], " ", terminator: "")
        }
        print("")
    }
}

print(triangle[40][20])
