#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_051.swift -o problem_051_swift" -*-
// Copyright (c) 2017 Michael Caldwell
import Foundation

func makeMask(prime: Int) -> Int {
    var mask = -1

    // Decompose number into array to look for repeating numbers
    var digits = [Int](repeating: 0, count: 10)
    for i in 1 ... 5 {
        let digit = prime / Int(pow(10.0, Float(i))) % 10
        digits[digit] += 1

        // If we find a number that repeats (at least) 3 times, we will use it 
        if digits[digit] == 3 {

            // Create a "mask" by decomposing the number again, and supplying 1 for any digit
            // that matches the repeating digit, and 0 otherwise
            mask = 0
            for n in (1...5).reversed() {
                if (prime / Int(pow(10.0, Float(n))) % 10) == digit {
                    mask += 1
                }
                mask *= 10
            }
            break
        }
    }

    return mask
}

print("Project Euler - Problem 51:")
print("Find the smallest prime which, by replacing part of the number with the same digit, is part of an eight prime value family.\n")

var primeSieve = [Int](repeating: 1, count: 999999)
var primes = [Int]()

// We are only interested in 6-digit primes for this problem
for i in 2 ..< primeSieve.count {
    if primeSieve[i] == 1 {
        if i > 100000 { primes.append(i) }
        var m = 2
        while m * i < primeSieve.count {
            primeSieve[m*i] = 0
            m += 1
        }
    }
}

var answer = 0

for prime in primes {
    // Create "mask" based on repeating digits
    var mask = makeMask(prime: prime)

    // If no repeating digits, skip to next prime
    if mask == -1 { continue }

    var count = 1
    var temp = prime
    for i in 1 ... 9 {
        // Add mask to number - This will only increment the repeating digits
        temp += mask

        // See if new number is prime (and in range)
        if temp < 999999 && primeSieve[temp] == 1 {
            count += 1
        }

        // Give up if we haven't found enough
        if i > 3 && count < 2 { break }

        // If we find 8, we've found our answer
        if count == 8 {
            answer = prime
            break
        }
    }

    if answer != 0 { break }
}

print(answer)
