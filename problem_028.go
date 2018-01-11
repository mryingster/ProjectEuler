// -*- compile-command: "go build -o problem_028_go problem_028.go" -*-
// Copyright (c) 2018 Michael Caldwell
package main

import "fmt"

// 21 22 23 24 25
// 20 07 08 09 10
// 19 06 01 02 11
// 18 05 04 03 12
// 17 16 15 14 13

func main() {
	fmt.Println("Project Euler - Problem 28")
	fmt.Println("Starting with the number 1 and moving to the right in a clockwise direction, form a 1001 by 1001 spiral. What is the sum of the numbers on the diagonals in this spiral?\n")

	sum := 1
	pos := 1

	for i := 2; i <= 1001; i+=2 {
		for s := 0; s <4; s++ {
			pos += i
			sum += pos
		}
	}

	fmt.Println(sum)
}
