// -*- compile-command: "go build -o problem_001_go problem_001.go" -*-
// Copyright (c) 2016 Michael Caldwell
package main

import "fmt"

func main() {
	fmt.Println("Project Euler - Problem 1")
	fmt.Println("Find the sum of all the multiples of 3 or 5 below 1000.\n")

	sum := 0

	for n := 1; n < 1000; n++ {
		if n % 3 == 0 || n % 5 == 0 {
			 sum = sum + n
		}
	}

	fmt.Println(sum)
}
