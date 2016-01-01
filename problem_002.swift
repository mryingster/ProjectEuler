#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_001.swift -o problem_001" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 2:")
print("By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\n")

let limit = 4000000
var total = 0

var a = 1
var b = 1
var c = 1

while a < limit {
    a = b + c
    c = b
    b = a
    if b % 2 == 0 {
        total += b
    }
}

print(total)
