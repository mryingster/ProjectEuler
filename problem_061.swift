#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_061.swift -o problem_061_swift" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

func isMatch(a: Int, b: Int) -> Bool {
    return a % 100 == b / 100
}

func solve(gonal: [[Int]], debug: Bool) -> Int {
    // Iterate through all the numbers looking for cyclical set
    for a in gonal {
        var history = [a[1], 0, 0, 0, 0, 0]

        for b in gonal {
            if isMatch(a: a[0], b: b[0]) && history.contains(b[1]) == false {
                history[1] = b[1]

                for c in gonal {
                    if isMatch(a: b[0], b: c[0]) && history.contains(c[1]) == false {
                        history[2] = c[1]

                        for d in gonal {
                            if isMatch(a: c[0], b: d[0]) && history.contains(d[1]) == false {
                                history[3] = d[1]

                                for e in gonal {
                                    if isMatch(a: d[0], b: e[0]) && history.contains(e[1]) == false {
                                        history[4] = e[1]

                                        for f in gonal {
                                            if isMatch(a: e[0], b: f[0]) && history.contains(f[1]) == false {
                                                history[5] = f[1]

                                                if isMatch(a: f[0], b: a[0]) {
                                                    if debug == true{
                                                        print(a[0], b[0], c[0], d[0], e[0], f[0])
                                                    }
                                                    return a[0] + b[0] + c[0] + d[0] + e[0] + f[0]
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0
}

print("Project Euler - Problem 61:")
print("Find the sum of the only ordered set of six cyclic 4-digit numbers for which each polygonal type: triangle, square, pentagonal, hexagonal, heptagonal, and octagonal, is represented by a different number in the set.\n")

let debug = false

// Generate our gonal numbers in the 4 digit range
var gonal = [[Int]]()
for i in 0...200 {
    var t = i * (i + 1)/2
    if t > 999 && t < 10000 { gonal.append([t, 3])}
    t = i * i
    if t > 999 && t < 10000 { gonal.append([t, 4])}
    t = i * (3*i - 1)/2
    if t > 999 && t < 10000 { gonal.append([t, 5])}
    t = i * (2*i - 1)
    if t > 999 && t < 10000 { gonal.append([t, 6])}
    t = i * (5*i - 3)/2
    if t > 999 && t < 10000 { gonal.append([t, 7])}
    t = i * (3*i - 2)
    if t > 999 && t < 10000 { gonal.append([t, 8])}
}

print(solve(gonal: gonal, debug: debug))
