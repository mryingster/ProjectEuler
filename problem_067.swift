#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_067.swift -o problem_067_swift" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

func debugPrint(a: [[Int]]) -> Void {
    for row in 0 ..< a.count {
        for col in 0 ..< a[row].count {
            if a[row][col] == 0 {
                break
            }
            print(a[row][col], terminator: " ")
        }
        print("")
    }
}

print("Project Euler - Problem 67:")
print("Find the maximum total from top to bottom in a triangle with one-hundred rows.\n")

let debug = false

// Import data from file
let file: FileHandle? = FileHandle(forReadingAtPath: "problem_067.txt")
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
var array = [[Int]]()
var inputArray = dataAsString!.components(separatedBy:"\n")
for i in 0 ..< inputArray.count - 1{
    var rowArray = [Int]()

    // Split row into array, convert to int and put into rowArray
    let tmp = inputArray[i].components(separatedBy:" ")
    for e in 0 ..< tmp.count {
        rowArray.append(Int(tmp[e])!)
    }

    // Pad rowArray out with 0's so final array is square
    for e in tmp.count...inputArray.count{
        rowArray.append(0)
    }

    // Append new rowArray to final array
    array.append(rowArray)
}

if debug == true {
    debugPrint(a: array)
}

// Solve - Start from bottom
for row in (0 ..< array.count-1).reversed() {
    for col in 0 ..< array.count {
        if array[row+1][col] > array[row+1][col+1] {
            array[row][col] += array[row+1][col]
        } else {
            array[row][col] += array[row+1][col+1]
        }
    }
}

// Print cell 0, 0!
print(array[0][0])

if debug == true {
    debugPrint(a: array)
}
