#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_003.swift -o problem_003" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 3:")
print("What is the largest prime factor of the number 600851475143?\n")

var n = 600851475143
var d = 2

while d < n {
    if n % d == 0 {
        n /= d
    } else {
        d += 1
    }
}

print(d)
