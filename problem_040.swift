#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_040.swift -o problem_040" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa

print("Project Euler - Problem 40:")
print("If dn represents the nth digit of the fractional part, find the value of the following expression.\nd1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000 \n")

var array = [0]
for n in 1...1000000 {
    let l = Int(floor(log10(Float(n))))
    for i in (0...l).reverse() {
        var t = n / Int(pow(Float(10), Float(i)))
        t = t % 10
        array.append(t)
    }
    if array.count > 1000000 {
        break
    }
}

var answer = 1
for i in 1...6 {
    answer = answer * array[Int(pow(10.0, Float(i)))]
}

print(answer)
