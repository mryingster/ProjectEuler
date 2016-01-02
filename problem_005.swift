#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_005.swift -o problem_005" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 5:")
print("What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n")

let limit = 20
var n = limit

while true {
    n += limit
    var done = true

    for i in 2...limit {
        if n % i != 0 {
            done = false
            break
        }
    }

    if done == true {
        break
    }
}

print(n)
