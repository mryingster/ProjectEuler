// -*- compile-command: "go build -o problem_016_go problem_016.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
        fmt.Println("Project Euler - Problem 16:")
        fmt.Println("What is the sum of the digits of the number 2^1000\n")

	bigNumber := make([]int, 500)
	bigNumber[0] = 2
	debug := false

	for n := 1; n < 1000; n++ {
		// Multiply
		for i := 0; i < len(bigNumber); i++ {
			bigNumber[i] *= 2
		}

		// Carry
		for i := 0; i < len(bigNumber) - 1; i++ {
			for bigNumber[i] > 9 {
				bigNumber[i] -= 10
				bigNumber[i+1]++
			}
		}
	}

	// Print the big number
	if debug == true {
		print := false
		for i := len(bigNumber)-1; i >= 0; i-- {
			if bigNumber[i] != 0 { print = true }
			if print == true { fmt.Print(bigNumber[i]) }
		}
		fmt.Println("\n")
	}

	sum := 0
	// Add
	for i := 0; i < len(bigNumber); i++ {
		sum += bigNumber[i]
	}

        fmt.Println(sum)
}
