#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_058.swift -o problem_058_swift" -*-
// Copyright (c) 2016 Michael Caldwell

func isPrime(n:Int) -> Bool {
    if n < 2 { return false }
    if n == 2 { return true }
    if n % 2 == 0 { return false }

    var i = 3;
    while i * i <= n{
        if n % i == 0 {
            return false
        }
        i += 2
    }

    return true;
}

print("Project Euler - Problem 58:")
print("Start with 1 and spiral anticlockwise with numbers incrementing from 1 forming a square. What is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?\n")

let debug = false
var corners = 1
var primes = 0
var length = 2
var side = 0
var corner = 1

while Float(primes) / Float(corners) > 0.1 || primes == 0 {
    // Find next corner
    if side == 4 {
        side = 0
        length += 2
    }
    corner += length
    side += 1
    corners += 1

    // Check if next corner is prime
    if isPrime(n: corner) {
        primes += 1
    }

    if debug == true {
        print(side, length, corner, corners, primes, primes*100/corners)
    }
}

print(length + 1) // Includes both corners in length!
