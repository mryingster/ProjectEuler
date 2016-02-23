#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_036.swift -o problem_036" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 36:")
print("Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.\n")

func reverseString(let s:String) -> String {
    var r = ""
    for var i=s.characters.count-1; i>=0; i-- {
        r.append(s[s.startIndex.advancedBy(i)])
    }
    return r
}

func reverseInt(var n:Int) -> Int {
    var r = 0
    while n > 0 {
        r *= 10
        r += n % 10
        n /= 10
    }
    return r
}

var sum = 0
let limit = 1000000
let debug = false

for n in 0...limit {
    let nr = reverseInt(n)
    if nr == n {
        let b = String(n, radix: 2)
        let br = reverseString(b)
        if b == br {
            if debug == true {
                print(n, nr, b, br)
            }
            sum += n
        }
    }
}

print(sum)
