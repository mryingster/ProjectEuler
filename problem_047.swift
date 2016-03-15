#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_047.swift -o problem_047" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 47:")
print("What is the of four consecutive integers to have four distinct prime factors?\n")

func distinctFactors(var n:Int, primes:[Int]) -> Int {
    var index = 0
    var result = 0

    while n > 1 {
        var count = 0
        while n % primes[index] == 0 {
            n /= primes[index]
            if count == 0 {
                result += 1
            }
            count += 1
        }
        index += 1
    }

    return result
}

let limit = 500000
var primeSieve = [Int](count: limit, repeatedValue: 1)
primeSieve[0] = 0
primeSieve[1] = 0
var primes:[Int] = []
let target = 4
var count = 0
var answer = 0

for n in 2...limit {
    // If prime, make multiples as non-prime
    if primeSieve[n] == 1 {
        primes.append(n)
        for var i=2; i*n < primeSieve.count; i++ {
            primeSieve[n*i] = 0
        }
        count = 0

    } else {
        // If composite, check for # of factors
        let f = distinctFactors(n, primes:primes)

        // Keep track of how many composites have target number of factors
        if f == target {
            count += 1
        } else {
            count = 0
        }

        // If we have the correct number of numbers we have our answer
        if count == target {
            answer = n - target + 1
            break
        }
    }
}

print(answer)
