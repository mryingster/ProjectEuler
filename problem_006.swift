#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_006.swift -o problem_006" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 6:")
print("Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n")

var sqr = 0
var sum = 0

for i in 1...100 {
    sum += i*i
    sqr += i
}

sqr *= sqr

print(sqr-sum)
