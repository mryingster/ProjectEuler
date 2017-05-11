// -*- compile-command: "go build -o problem_009_go problem_009.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func findTriplet(limit int) int {
	for a := 1; a < limit/2; a++ {
		for b := a; b < limit/2; b++ {
			c := limit - a - b
			if c * c == (a * a) + (b * b) {
				return a * b * c
			}
		}
	}

	return 0
}

func main() {
        fmt.Println("Project Euler - Problem 9:")
        fmt.Println("There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.\n")

        fmt.Println(findTriplet(1000))
}

