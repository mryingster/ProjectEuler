// -*- compile-command: "go build -o problem_020_go problem_020.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
        fmt.Println("Project Euler - Problem 20:")
        fmt.Println("Find the sum of the digits in the number 100!\n")

	bigNumber := make([]int, 500)
	bigNumber[0] = 1
	debug := false

	for n := 1; n < 100; n++ {
		// Multiply
		for i := 0; i < len(bigNumber); i++ {
			bigNumber[i] *= n
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

	// Add
	sum := 0
	for i := 0; i < len(bigNumber); i++ {
		sum += bigNumber[i]
	}

        fmt.Println(sum)
}
