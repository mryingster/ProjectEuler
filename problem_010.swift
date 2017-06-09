#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_010.swift -o problem_010" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 10:")
print("Find the sum of all the primes below two million.\n")

func isPrime(n:Int) -> Bool {
    if n < 2 { return false }
    if n == 2 { return true }
    if n % 2 == 0 { return false }

    var i = 3
    while i * i <= n {
        if n % i == 0 {
            return false
        }
        i += 2
    }

    return true;
}

let limit = 2000000
var sum = 2

for var n in stride(from: 3, to: limit, by: 2) {
    if isPrime(n: n) == true {
        sum += n
    }
}

print(sum)
