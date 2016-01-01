#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_004.swift -o problem_004" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 4:")
print("Find the largest palindrome made from the product of two 3-digit numbers.\n")

func isPalindrome(input:Int) -> Bool {
    var r = 0
    var n = input
    while n > 0 {
        r *= 10
        r += n % 10
        n /= 10
    }

    if r == input {
        return true
    } else {
        return false
    }
}

var l = 0

for a in 900...999 {
    for b in 900...999 {
        var p = a * b
        if isPalindrome(p) == true && p > l {
            l = p
        }
    }
}

print(l)
