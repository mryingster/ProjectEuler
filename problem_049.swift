#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_049.swift -o problem_049" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 49:")
print("What 12 digit sequence do you form by concatenating three four-digit primes that are permutations of each other and increase by the same amount?\n")

func isPrime(n:Int) -> Bool {
    if n < 2 { return false }
    if n == 2 { return true }
    if n % 2 == 0 { return false }

    for var i = 3; i * i <= n ; i+=2 {
        if n % i == 0 {
            return false
        }
    }

    return true;
}

func getSig(var a:Int) -> [Int] {
    var aa = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    while a > 0 {
        aa[a%10] += 1
        a /= 10
    }

    return aa
}

var primes:[Int] = []
var signature:[[Int]] = []

for n in 1488...9999 {
    if isPrime(n) == true {
        primes.append(n)
        signature.append(getSig(n))
    }
}

var answer = "148748178147"

for a in 0...primes.count-1 {
    for b in a+1...primes.count-1 {
        if primes[a] + primes[b] > 9999 {
            break
        }

        if signature[a] == signature[b] {
            var c = primes[b] * 2 - primes[a]
            if primes.contains(c) {
                c = primes.indexOf(c)!
                if signature[a] == signature[c] {
                    answer = String(primes[a])+String(primes[b])+String(primes[c])
                    break
                }
            }
        }
    }
    if answer != "148748178147" {
        break
    }
}

print(answer)
