#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_025.swift -o problem_025" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 25:")
print("What is the first term in the Fibonacci sequence to contain 1000 digits?\n")

var a: [Int] = [1]
var b: [Int] = [0]
var c: [Int] = [0]
var index = 1

while a.count < 1000+1 {
    c = a

    for i in 0...b.count-1 {
        a[i] += b[i]
    }

    for i in 0...a.count-1 {
        if a.last != 0 { a.append(0) }
        while a[i] > 9{
            a[i+1] += 1
            a[i] -= 10
        }
    }

    b = c
    index += 1
}

print(index)
