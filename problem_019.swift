#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_019.swift -o problem_019" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 19:")
print("Find the total number of Sundays that fell on the first of the month in the 20th Century.\n")

var count = 0
var year = 1901 // 20th Century starts in 1901
var month = 1   // 1 = January, etc...
var date = 1    // Date of the month
var day = 2     // Day of the week, 1901 Starts on a Teusday (0 = sunday, etc...)

while year < 2001 {
    if date == 1 && day == 0 {count++ }

    var monthLength = 31
    if month == 4 || month == 6 || month == 9 || month == 11 {
        monthLength = 30
    } else if month == 2 {
        if year % 4 == 0 {
            monthLength = 29
        } else {
            monthLength = 28
        }
    }

    if ++day > 6 { day -= 7 }

    if ++date > monthLength {
        date = 1
        month++
    }

    if month > 12 {
        month = 1
        year++
    }
}

print(count)
