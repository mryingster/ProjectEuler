#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_070.swift -o problem_070_swift" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

func totient(n: Int, r: Double, primes: [Int]) -> Int {
    var n = n
    var result = Double(n)
    let threshold = Double(n) / r
    var i = 0

    while n > 1 && i < primes.count {
        if n % primes[i] == 0 {
            while n % primes[i] == 0 {
                n /= primes[i]
            }

            result *= (1.0 - (1.0/Double(primes[i])))

            if result <= threshold {
                return 1;
            }
        }
        i += 1;
    }

    return Int(result);
}

func numSig(n: Int) -> Int {
    var n = n
    var sig = 0
    while n > 0 {
        sig += Int(pow(10.0, Double(n % 10)))
        n /= 10
    }
    return sig
}

func numLength(n: Int) -> Int {
    return Int(floor(log10(Float(n))) + 1.0)
}

print("Project Euler - Problem 70:")
print("Find the value of n, 1 < n < 10^7, for which phi(n) is a permutation of n and the ratio n/phi(n) produces a minimum.\n")

var primeSieve = [Int](repeating: 1, count: 10000)
var primes = [Int]()

for i in 2 ..< primeSieve.count {
    if primeSieve[i] == 1 {
        primes.append(i)
        var m = 1
        while m * i < primeSieve.count {
            primeSieve[m*i] = 0
            m += 1
        }
    }
}

var ratio = 2.0
var minimum = 0
let limit = 10000000

// Combine two primes to produce number with good ratio
for a in primes {
    for b in primes {
        let i = a * b
        if i > limit { break}

        // Get totient
        let t = totient(n: i, r: ratio, primes: primes)

        // Check length of numbers first (Less computation)
        if numLength(n: t) != numLength(n: t) {
            continue
        }

        // Check number signatures to see if permutation
        if numSig(n: t) != numSig(n: i) {
            continue
        }

        ratio = Double(i)/Double(t)
        minimum = i
        //print(i, t, ratio)
    }
}

print(minimum)
//8319823
