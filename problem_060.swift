#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_060.swift -o problem_060_swift" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

func isPrime(n:Int) -> Bool {
    if n < 2 { return false }
    if n == 2 { return true }
    if n % 2 == 0 { return false }

    var i = 3;
    while i * i <= n{
        if n % i == 0 { return false }
        i += 2
    }

    return true
}

func concatenateInt(a: Int, b: Int) -> Int {
    let length = floor(log10(Float(b))) + 1.0
    var c = a * Int(pow(10.0, length))
    c += b
    return c
}

func checkPrimeConcatenation(a: Int, b: Int) -> Bool {
    let aPrime = concatenateInt(a: a, b: b)
    if isPrime(n: aPrime) == false {
        return false
    }

    let bPrime = concatenateInt(a: b, b: a)
    if isPrime(n: bPrime) == false {
        return false
    }

    return true
}

func findSolution(primes: [Int], debug: Bool) -> Int{
    for a in 0 ..< primes.count {
        for b in 0 ..< primes.count {
            if checkPrimeConcatenation(a: primes[a], b: primes[b]) == false { continue }

            for c in 0 ..< primes.count {
                if checkPrimeConcatenation(a: primes[a], b: primes[c]) == false { continue }
                if checkPrimeConcatenation(a: primes[b], b: primes[c]) == false { continue }

                for d in 0 ..< primes.count {
                    if checkPrimeConcatenation(a: primes[a], b: primes[d]) == false { continue }
                    if checkPrimeConcatenation(a: primes[b], b: primes[d]) == false { continue }
                    if checkPrimeConcatenation(a: primes[c], b: primes[d]) == false { continue }

                    for e in 0 ..< primes.count {
                        if checkPrimeConcatenation(a: primes[a], b: primes[e]) == false { continue }
                        if checkPrimeConcatenation(a: primes[b], b: primes[e]) == false { continue }
                        if checkPrimeConcatenation(a: primes[c], b: primes[e]) == false { continue }
                        if checkPrimeConcatenation(a: primes[d], b: primes[e]) == false { continue }

                        // If we got here, we foudn a solution!
                        if debug == true {
                            print(primes[a], primes[b], primes[c], primes[d], primes[e])
                        }
                        return primes[a] + primes[b] + primes[c] + primes[d] + primes[e]
                    }
                }
            }
        }
    }
    return 0
}

print("Project Euler - Problem 60:")
print("Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.\n")

let debug = false

// Populate primes list
let limit = 10000
var primeSieve = [Int](repeating: 1, count: limit)
primeSieve[0] = 0
primeSieve[1] = 0
var primes:[Int] = []

for n in 2...limit-1 {
    if primeSieve[n] == 1 {
        primes.append(n)
        var i=2
        while i*n < primeSieve.count{
            primeSieve[n*i] = 0
            i += 1
        }
    }
}

// Brute force a solution!
var solution = findSolution(primes: primes, debug: debug)

print(solution)
