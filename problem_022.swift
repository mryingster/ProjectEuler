#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_022.swift -o problem_022" -*-
// Copyright (c) 2016 Michael Caldwell
import Cocoa
import Darwin

print("Project Euler - Problem 22:")
print("Sort 5000 names and calculate the sum of their name scores.\n")

func name_score(name: String) -> Int {
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

// Import data from file
let file: NSFileHandle? = NSFileHandle(forReadingAtPath: "problem_022.txt")
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

// Separate names into array
var names = dataAsString!.componentsSeparatedByString(",")

// Sort names alphabetically
names.sortInPlace { return $0 < $1 }

// Calculate name score
var total = 0
for i in 1...names.count {
    let score = name_score(names[i-1])
    total += score * i
}

print(total)
