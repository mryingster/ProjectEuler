#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_047.swift -o problem_047" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 47:")
print("What is the of four consecutive integers to have four distinct prime factors?\n")

let limit = 500000
var primeSieve = [Int](count: limit, repeatedValue: 0)
var count = 4

for n in 2...limit-1 {
    // If prime, mark multiples as non-prime
    if primeSieve[n] == 0 {
        var i=1
        repeat {
            primeSieve[n*i] += 1
            i += 1
        } while i*n < primeSieve.count

    }

    // Look for four in a row
    if primeSieve[n] == 4 {
        count -= 1
        if count == 0 {
            count = n - 3
            break
        }
    } else {
        count = 4
    }
}

print(count)
