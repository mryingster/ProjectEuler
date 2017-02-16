#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_0032.swift -o problem_0032" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 32:")
print("Find the sum of all numbers that can be written as pandigital products.\n")

func isPandigital(var a:Int, var b:Int, var c:Int) -> Bool {
    var count = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    while a > 0 {
        if count[a%10] > 0 { return false }
        count[a%10] += 1
        a /= 10
    }

    while b > 0 {
        if count[b%10] > 0 { return false }
        count[b%10] += 1
        b /= 10
    }

    while c > 0 {
        if count[c%10] > 0 { return false }
        count[c%10] += 1
        c /= 10
    }

    for i in 0...count.count-1 {
        if count[i] != 1{
            return false
        }
    }

    return true
}

var panProduct: [Int] = [0]
var sum = 0
let limit = 2500

for a in 0...limit {
    for b in a...limit {
        let c = a * b
        if isPandigital(a, b:b, c:c) {
            var add = true
            for i in 0...panProduct.count-1 {
                if panProduct[i] == c {
                    add = false
                    break
                }
            }
            if add == true {
                panProduct.append(c)
                sum += c
            }
        }
    }
}

print(sum)
