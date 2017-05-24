// -*- compile-command: "go build -o problem_019_go problem_019.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
        fmt.Println("Project Euler - Problem 19")
        fmt.Println("Find the total number of Sundays that fell on the first of the month in the 20th Century.\n")

	sum := 0

	//      January 1901
	//  Su Mo Tu We Th Fr Sa
	//         1  2  3  4  5
	//   6  7  8  9 10 11 12
	//  13 14 15 16 17 18 19
	//  20 21 22 23 24 25 26
	//  27 28 29 30 31

	dayOfWeek := 2
	dateOfMonth := 1
	monthOfYear := 1
	year := 1901
	
	for year < 2001 {
		dayOfWeek++
		dayOfWeek %= 7

		dateOfMonth++

		// February
		if monthOfYear == 2 {
			// Leap Year
			if year % 4 == 0 {
				if dateOfMonth == 30 {
					dateOfMonth = 1
					monthOfYear++
				}
			} else {
				if dateOfMonth == 29 {
					dateOfMonth = 1
					monthOfYear++
				}
			}
		}


		// 30 Day Months
		if monthOfYear < 8 && monthOfYear % 2 == 0 || monthOfYear > 8 && monthOfYear %2 != 0 {
			if dateOfMonth == 31 {
				dateOfMonth = 1
				monthOfYear++
			}
		// 31 Day Months
		} else {
			if dateOfMonth == 32 {
				dateOfMonth = 1
				monthOfYear++
			}
		}

		// New Year
		if monthOfYear == 13 {
			monthOfYear = 1
			year++
		}

		// Check for Sunday on First condition
		if dayOfWeek == 0 && dateOfMonth == 1 {
			sum ++
		}
	}

        fmt.Println(sum)
}
