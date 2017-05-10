// -*- compile-command: "go build -o problem_006_go problem_006.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
        fmt.Println("Project Euler - Problem 6:")
        fmt.Println("Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n")

	squareOfSums := 0
	sumOfSquares := 0
	limit := 100

	for i := 1; i <= limit; i++ {
		squareOfSums += i
		sumOfSquares += i*i
	}

	squareOfSums *= squareOfSums

        fmt.Println(squareOfSums - sumOfSquares)
}

