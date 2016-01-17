#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_018.swift -o problem_018" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 18:")
print("Find the maximum total from top to bottom of the triangle below:\n")

var triangle: [[Int]] = [[75],
                         [95,64],
                         [17,47,82],
                         [18,35,87,10],
                         [20, 4,82,47,65],
                         [19, 1,23,75, 3,34],
                         [88, 2,77,73, 7,63,67],
                         [99,65, 4,28, 6,16,70,92],
                         [41,41,26,56,83,40,80,70,33],
                         [41,48,72,33,47,32,37,16,94,29],
                         [53,71,44,65,25,43,91,52,97,51,14],
                         [70,11,33,28,77,73,17,78,39,68,17,57],
                         [91,71,52,38,17,14,91,43,58,50,27,29,48],
                         [63,66, 4,68,89,53,67,30,73,16,69,87,40,31],
                         [04,62,98,27,23, 9,70,98,73,93,38,53,60, 4,23]];

for var y = 0 ; y < triangle.count ; y++ {
    for var i in 0...(triangle.count-y-1) {
        print("  ", terminator: "")
    }
    for var x = 0 ; x < triangle[y].count ; x++ {
        print(String(format: "%02d  ", triangle[y][x]), terminator: "")
    }
    print("")
}
print("")

for var y = triangle.count-2 ; y >= 0 ; y-- {
    for var x = 0 ; x < triangle[y].count ; x++ {
        if triangle[y+1][x] > triangle[y+1][x+1] {
            triangle[y][x] +=  triangle[y+1][x]
        } else {
            triangle[y][x] +=  triangle[y+1][x+1]
        }
    }
}

print(triangle[0][0])
