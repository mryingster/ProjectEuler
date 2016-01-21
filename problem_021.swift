#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_021.swift -o problem_021" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 21:")
print("Evaluate the sum of all the amicable numbers under 10000.\n")

func sumDivisors(n:Int) -> Int {
    var s = 0
    for d in 1...n/2+1 {
        if n % d == 0 {
            s += d
        }
    }
    return s
}

var sum = 0
for n in 1...10000 {
    var a = sumDivisors(n)
    var b = sumDivisors(a)

    if b == n && b != a {
        sum += n
        //print(n, a, b)
    }
}

print(sum)
