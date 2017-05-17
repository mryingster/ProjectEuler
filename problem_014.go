// -*- compile-command: "go build -o problem_014_go problem_014.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
        fmt.Println("Project Euler - Problem 14:")
        fmt.Println("Which starting number, under one million, produces the longest chain by following the rules below?\n")
	fmt.Println("if n is even, n/2")
	fmt.Println("if n is odd, 3n+1\n")


	limit := 1000000
	history := make([]int, limit)
	longest := 0

	for n := 2 ; n < limit; n++ {
		chain := 0
		number := n
		for number > 1 {
			// Follow rules
			if number % 2 == 0 {
				number /= 2
			} else {
				number = number * 3 + 1
			}
			chain++

			//check history to see if we can end early
			if number < limit && history[number] != 0 {
				chain += history[number]
				number = 1
			}
		}


		// Record history
		history[n] = chain

		// Check for new winner
		if chain > history[longest] {
			longest = n
		}
	}

	fmt.Println(longest)
}
