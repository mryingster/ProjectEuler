#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_001.swift -o problem_001" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 45:")
print("Find the next triangle number after 40755 that is also pentagonal and hexagonal.\n")

struct Agonal {
    var index = 0
    var value = 0
}

var tri  = Agonal(index: 285, value: 40755)
var pent = Agonal(index: 165, value: 0)
var hex  = Agonal(index: 143, value: 0)

while tri.value != hex.value || tri.value != pent.value {
    tri.index += 1
    tri.value = tri.index * (tri.index + 1) / 2
    while pent.value < tri.value {
          pent.index += 1
          pent.value = pent.index * (3 * pent.index - 1) / 2
    }
    while hex.value < tri.value {
        hex.index += 1
        hex.value = hex.index * (2 * hex.index - 1)
    }
}

print(tri.value)
