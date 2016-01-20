#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_019.swift -o problem_019" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 19:")
print("Find the sum of the digits in the number 100!\n")

var n: [Int] = [1]

for e in 1...100 {
    for i in 0...n.count-1 {
        n[i] *= e
    }

    for i in 0...n.count-1 {
        while n[i] > 9{
            if n.last != 0 { n.append(0) }
            n[i+1] += 1
            n[i] -= 10
        }
    }
}

var sum = 0
for i in 0...n.count-1 {
    sum += n[i]
}

print(sum)
