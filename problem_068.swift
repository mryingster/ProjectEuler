#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_068.swift -o problem_068_swift" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

func nextPermutation(a: [Int]) -> [Int] {
    var a = a

    // Find the largest index k such that a[k] < a[k + 1]
    var k = 0
    for i in 0 ..< a.count - 1 {
        if a[i] < a[i+1] {
            k = i
        }
    }

    // Find the largest index l greater than k such that a[k] < a[l]
    var l = 0
    for i in k ..< a.count {
        if a[k] < a[i] {
            l = i
        }
    }

    // Swap the value of a[k] with that of a[l]
    let t = a[k]
    a[k] = a[l]
    a[l] = t

    // Reverse the sequence from a[k + 1] up to and including the final element a[n]
    if k < a.count - 1 {
        var r = [Int](repeating: 0, count: a.count)
        var j = a.count - 1
        for i in (k+1) ..< a.count {
            r[j] = a[i]
            j -= 1
        }
        for i in (k+1) ..< a.count {
            a[i] = r[i]
        }
    }

    return a
}

func factorial(n: Int) -> Int {
    var n = n
    var result = 1
    while n > 1 {
        result *= n
        n -= 1
    }
    return result
}

func checkSolution(o: [Int], i: [Int]) -> String {
    var result = ""
    let target = o[0] + i[0] + i[1]
    let length = o.count

    // Compare each triplet's sum against the first
    for p in 0 ..< length {
        // Return a blank string if sum is not correct
        if o[p] + i[p] + i[(p+1)%length] != target {
            return ""
        }

        // Append our new numbers to the string if sum is correct
        result += String(o[p]) + String(i[p]) + String(i[(p+1)%length])
    }

    return result
}

print("Project Euler - Problem 68:")
print("Find the maximum concatenation for a 16 digit string for a solution to a \"magic 5-gon ring\" using the numbers 1-10?\n")

var outer = [6, 7, 8, 9, 10]
let length = outer.count
let num_permutations = factorial(n: length)
var solution = ""

// Go through permutations of the outside number
for _ in 0 ..< num_permutations {
    outer = nextPermutation(a: outer)

    // Go through permutations of the inside number
    var inner = [1, 2, 3, 4, 5]
    for _ in 0 ..< num_permutations {
        inner = nextPermutation(a: inner)

        // See if we found a solution
        solution = checkSolution(o: outer, i: inner)

        // Non-empty string means we found a solution. Break!
        if solution != "" {
            break
        }
    }
    if solution != "" {
        break
    }
}

print(solution)
