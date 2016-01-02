#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_007.swift -o problem_007" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 7:")
print("What is the 10,001st prime number?\n")

func isPrime(n:Int) -> Bool {
    if n < 2 { return false }
    if n == 2 { return true }
    if n % 2 == 0 { return false }

    for  var i = 3; i * i <= n ; i+=2 {
        if n % i == 0 {
            return false
        }
    }

    return true;
}

let limit = 10001
var n = 3
var c = 2

while c < limit {
    n += 2
    if isPrime(n) == true {
        c++
    }
}

print(n)
