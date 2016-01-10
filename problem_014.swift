#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_014.swift -o problem_014" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 14:")
print("Which starting number, under one million, produces the longest chain by following the rules below?\n")

print("if n is even, n/2\nif n is odd, 3n+1\n")

func length(let input: Int, let history: [Int]) -> Int {
    var n = input
    var c = 1

    while n != 1 {
        if n < input {
            if history[n] == -1 {
                return -1
            } else {
                return history[n]+c
            }
        }

        if n % 2 == 0 {
            n /= 2
        } else {
            n *= 3
            n++
        }

        c++

        if n == input {
             return -1
        }
    }

    return c
}

var history: [Int] = [0, 1]
var maxN = 0
var maxC = 0

for i in 2...1000000 {
    history.append(length(i, history: history))
    if history[i] > maxC {
        maxC = history[i]
        maxN = i
    }
}

print(maxN, "Chain:", maxC)
