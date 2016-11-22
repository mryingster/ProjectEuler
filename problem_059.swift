#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_059.swift -o problem_059_swift" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

func decipher(a: Int, b: Int, c: Int, data: [String]) -> Int {
    let cipher = [a, b, c]
    var deciphered = ""
    var wordLength = 0
    var count = 0

    for i in 0 ..< data.count {
        // XOR and append to string
        let char = Int(data[i])! ^ (cipher[i%3] + Int(("a" as UnicodeScalar).value))
        count += char
        deciphered += String(format: "%c", char) as String

        // Look for unlikely characters
        if char > Int(("z" as UnicodeScalar).value) || char < Int((" " as UnicodeScalar).value) {
            return 0
        }

        // Look for unlikely word lengths
        wordLength += 1
        if char == Int((" " as UnicodeScalar).value) { wordLength = 0 }
        if wordLength > 13 { return 0 }
    }

    // If we get here, we found a probably valid message; Print it!
    let startingValue = Int(("a" as UnicodeScalar).value)
    print(String(format: "Cipher: %c%c%c", a+startingValue, b+startingValue, c+startingValue) as String)
    print(deciphered)
    print("")

    return count
}

print("Project Euler - Problem 59:")
print("Decrypt the message and find the sum of the ASCII values in the original text.\n")

// Import data from file
let file: FileHandle? = FileHandle(forReadingAtPath: "problem_059.txt")
if file == nil {
    print("Unable to open file.")
    exit(1)
}

// Read all the data
let data = file?.readDataToEndOfFile()

// Close the file
file?.closeFile()

// Convert our data to string
let dataAsString = String(data: data!, encoding: String.Encoding.utf8)

// Separate numbers into array
var array = dataAsString!.components(separatedBy:",")

// Brute force!
var result = 0

for A in 0...25 {
    for B in 0...25 {
        for C in 0...25 {
            result = decipher(a:A, b:B, c:C, data:array)
            if result != 0 { break }
        }
        if result != 0 { break }
    }
    if result != 0 { break }
}

print(result)
