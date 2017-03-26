#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_065.swift -o problem_065_swift" -*-
// Copyright (c) 2016 Michael Caldwell

/* Notes
 *                         (m)
 * Multipliers: 2   1   2   1   1   4   1   1   6   1   1
 * Numerators:  2   3   8   11  19  87 106 193
 *             (c) (b) (a)
 *
 * To calculate position a, a=b*m+c
 * This starts by calculating the second numerator (3),
 * and assumes 1 for the numerator to the left of 2
 * Multiplier continue in the same pattern of increasing by 2
 */

// Multiplies each element of array by n
func multiply_array(a:[Int], n:Int) -> [Int]{
    var a = a
    for i in 0 ..< a.count {
        a[i] *= n
    }
    return carry_array(a: a)
}

// Adds two arrays together
func add_array(a:[Int], b:[Int]) -> [Int] {
    var a = a
    for i in 0 ..< a.count {
        a[i] += b[i]
    }
    return carry_array(a: a)
}

// Performs carry operation so each element is single digit
func carry_array(a:[Int]) -> [Int] {
    var a = a
    for i in 0 ..< a.count-1 {
        while a[i] > 9 {
            a[i] -= 10
            a[i+1] += 1
        }
    }
    return a
}

print("Project Euler - Problem 65:")
print("Find the sum of the numerator of the 100th convergent fraction for e.\n")

let debug = false

var num_a = [Int](repeating: 0, count: 100)
var num_b = [Int](repeating: 0, count: 100)
var num_c = [Int](repeating: 0, count: 100)

num_a[0] = 2
num_b[0] = 1

var multiplier = 0
var count = 1

for _ in 1 ..< 100 {
    var m = 1
    count += 1

    // Keep track of multipliers
    if count == 3 {
        count = 0
        multiplier += 2
        m = multiplier
    }

    // Convergent Fraction
    num_c = num_b
    num_b = num_a
    num_a = multiply_array(a: num_b, n: m)
    num_a = add_array(a: num_a, b: num_c)

    // Debug print numerator for each step
    if debug == true {
        var p = false
        for i in (0 ..< num_a.count).reversed() {
            if num_a[i] > 0 { p = true }
            if p == true {
                print(num_a[i])
            }
        }
        print("")
    }
}

// Sum the digits
var sum = 0
for i in 0 ..< num_a.count {
    sum += num_a[i]
}

print(sum)
