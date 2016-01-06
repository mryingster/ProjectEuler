#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_011.swift -o problem_011" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 11:")
print("What is the value of the first triangle number to have over five hundred divisors?\n")

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

func findDivisors (var n: Int, _ p: [Int]) -> Int {
    var d = [Int:Int]()

    // Prime Factorization
    var i = 0
    while i < p.count && n > 1 {
        var c = 0
        while n % p[i] == 0 {
            c++;
            n /= p[i]
        }
        if c > 0 {
            d[p[i]] = c
        }
        i++
    }

    // Convert o normal factorization
    var result = 1
    for i in d.values {
        result *= i+1
    }

    return result
}

var primes = [Int]()
for var n in 2...1500 {
    if isPrime(n) == true {
        primes.append(n)
    }
}

var triangle = 1
var count = 1
var divisors = 0

while divisors < 500 {
    count++
    triangle += count
    if triangle % 100 != 0 {
        continue
    }
    divisors = findDivisors(triangle, primes)
}

print(triangle)
