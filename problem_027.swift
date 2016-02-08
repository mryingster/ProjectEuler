#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_027.swift -o problem_027" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 27:")
print("Find the product of the coefficients, a and b, for the quadratic expression, n^2 + an + b, that produces the maximum number of primes for consecutive values of n, starting with n = 0.\n")

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

let limit = 1000
var max = [0, 0]

for var a = limit * -1; a < limit; a += 1 {
    for var b = a ; b < limit; b += 1 {
        var n = 0
        var c = 0
        var equation = (n * n) + (a * n) + b
        while isPrime(equation) {
            c += 1
            n += 1
            equation = (n * n) + (a * n) + b
        }
        if c > max[0] {
            max[0] = c
            max[1] = a * b
        }
    }
}

print(max[1], "(\(max[0]) primes)")
