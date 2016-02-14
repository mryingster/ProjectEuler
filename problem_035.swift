#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_035.swift -o problem_035" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 35:")
print("How many circular primes are there below one million?\n")

func isPrime(n:Int) -> Bool {
    if n < 2 { return false }
    if n == 2 { return true }
    if n % 2 == 0 { return false }

    for  var i = 3; i * i <= n ; i+=2 {
        if n % i == 0 {
            return false
        }
    }

    return true;
}

func isCircular(var n:Int) -> Bool {
    if n < 10 { return true}
    let digits = floor(log10(Float(n)))
    for _ in 0...Int(digits)-1 {
        // Rotate
        let t = n % 10
        n /= 10
        n += t * Int(pow(10.0, digits))

        // And try
        if isPrime(n) == false {
            return false
        }
    }
    return true
}

let limit = 1000000
var count = 0

for n in 2...limit {
    if isPrime(n) == true {
        if isCircular(n) == true {
            count += 1
        }
    }
}

print(count)
