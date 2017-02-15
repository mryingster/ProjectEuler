#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_031.swift -o problem_031_swift -O" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

print("Project Euler - Problem 31:");
print("How many different ways can 2 pounds be made using any number of coins?\n");

func sumPartialArray(a:[Int], start:Int) -> Int {
    var sum = 0;
    for i in start ..< a.count {
        sum += a[i]
    }

    return sum
}

let coins = [1, 2, 5, 10, 20, 50, 100, 200]
var counter = [Int](repeating: 0, count: coins.count)
var count = 0;

while counter[counter.count-1] <= 200 {
    // Add enough pennies to get our next sum
    let sum = sumPartialArray(a:counter, start:0)
    if sum < 200 {
        counter[0] += 200 - sum
    }

    // Overflow when a counter element has become too full
    for c in 0 ... 6 {
        if counter[c] > 200 - sumPartialArray(a:counter, start:c+1) {
            counter[c] = 0
            counter[c+1] += coins[c+1]
        }
    }

    // If array adds up to 200, solution found
    if sumPartialArray(a:counter, start:0) == 200 {
        count += 1
        // Prep pennies column for next roll-over
        counter[0] = 201
    }
}

print(count)
//3.6
