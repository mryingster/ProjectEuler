#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_048.swift -o problem_048" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 48:")
print("Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.\n")

var n = 0
for i in 1...1000 {
    var t = 1
    for j in 1...i {
        t = t * i
        t = t % 10000000000
    }
    n += t
    n = n % 10000000000
}

print(n)
