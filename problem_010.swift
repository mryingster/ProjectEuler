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

    for var i = 3; i * i <= n ; i+=2 {
        if n % i == 0 {
            return false
        }
    }

    return true;
}

let limit = 2000000
var sum = 2

for var n = 3 ; n<limit ; n+=2 {
    if isPrime(n) == true {
        sum += n
    }
}

print(sum)
