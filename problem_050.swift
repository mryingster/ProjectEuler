#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_050.swift -o problem_050" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 50:")
print("Which prime, below one-million, can be written as the sum of the most consecutive primes?\n")

let limit = 1000000
var primeSieve = [Int](count: limit, repeatedValue: 1)
primeSieve[0] = 0
primeSieve[1] = 0
var primes:[Int] = []

// Populate primes list
for n in 2...limit-1 {
    if primeSieve[n] == 1 {
        primes.append(n)
        for var i=2; i*n < primeSieve.count; i++ {
            primeSieve[n*i] = 0
        }
    }
}

struct ConsecutivePrimes {
    var count = 0
    var value = 0
}

var max = ConsecutivePrimes()
for i in 0...100 {
    var current = ConsecutivePrimes()
    for p in i...primes.count-1 {
        current.value += primes[p]
        current.count += 1

        if current.value >= limit {
            break
        }
        if primeSieve[current.value] == 1 {
            if current.count > max.count {
                max.count = current.count
                max.value = current.value
            }
        }
    }
}

print(max.value)
