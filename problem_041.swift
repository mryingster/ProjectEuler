#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_041.swift -o problem_041" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 41:")
print("What is the largest n-digit pandigital prime that exists?\n")

func isPrime(n:Int) -> Bool {
    if n < 2 { return false }
    if n == 2 { return true }
    if n % 2 == 0 { return false }

    for  i in 3.stride(to: Int(sqrt(Float(n))), by: 2) {
        if n % i == 0 {
            return false
        }
    }

    return true;
}

func isPandigital(n:Int) -> Bool {
    var n = n
    let l = Int(floor(log10(Float(n))))+1
    var t = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    while n > 0 {
        let d = n % 10
        n /= 10
        if t[d] >= 1 {
            return false
        }
        if d > l {
            return false
        }
        t[d] += 1
    }
    return true
}

for n in 7654321.stride(to: 0, by: -9) {
    if isPrime(n) {
        if isPandigital(n) {
            print(n)
            break
        }
    }
}
