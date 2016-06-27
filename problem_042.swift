#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_042.swift -o problem_042" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa
import Darwin

print("Project Euler - Problem 42:")
print("In a list of two-thousand common English words, how many are triangle words?\n")

func wordScore(name: String) -> Int {
    var score = 0
    let characterArray = Array(name.characters)
    for character in characterArray {
        // Convert to ASCII value
        let scaler = String(character).unicodeScalars
        let asciiValue = scaler[scaler.startIndex].value
        // Skip quotes
        if character == "\"" { continue }
        // Convert to alphabetic value
        let charValue = asciiValue - UInt32("@")
        score += Int(charValue)
    }
    return score
}

func isTriangle(n: Int) -> Bool {
    if n == 0 {
        return false
    }

    let check: Float = (sqrt(Float(8 * n + 1)) - 1) / 2

    // See if number is integer
    if check == Float(Int(check)) {
        return true
    }

    return false
}

// Import data from file
let file: NSFileHandle? = NSFileHandle(forReadingAtPath: "problem_042.txt")
if file == nil {
    print("Unable to open file.")
    exit(1)
}

// Read all the data
let data = file?.readDataToEndOfFile()

// Close the file
file?.closeFile()

// Convert our data to string
let dataAsString = String(data: data!, encoding: NSUTF8StringEncoding)

// Separate words into array
var words = dataAsString!.componentsSeparatedByString(",")

// Calculate word score and check if is triangle number
var total = 0
for i in 1...words.count {
    if isTriangle(wordScore(words[i-1])) {
        total += 1
    }
}

print(total)
