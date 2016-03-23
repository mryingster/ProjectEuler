#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_001.swift -o problem_001" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 44:")
print("Find the smallest pair of pentagonal numbers whose sum and difference is pentagonal.\n")

func isPentagonal(number:Int) -> Bool {
    let check = (sqrt(24*Float(number)+1)+1)/6;
    if check == Float(Int(check)) {
        return true
    }
    return false
}

var pentagonal = [Int]()
var answer = 0

for i in 1...5000 {
    let sum = i * (3 * i - 1) / 2
    pentagonal.append(sum)
    //print(sum)

    for n in (0...i-1).reverse() {
        let a = pentagonal[n]
        let b = sum - a
        let diff = a - b
        if diff <= 0 { break }

        if isPentagonal(b) == true && isPentagonal(diff) == true{
            answer = diff
            break
        }
    }
    if answer != 0 {
        break
    }
}

print(answer)
