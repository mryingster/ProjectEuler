// -*- compile-command: "go build -o problem_015_go problem_015.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
	fmt.Println("Project Euler - Problem 15")
	fmt.Println("Starting in the top left corner in a 20 by 20 grid, how many routes are there to the bottom right corner?\n")

	pascal := [][]int{{1, 0}}
	limit := 20
	debug := false

	// Create Pascal's Triangle
	for y := 0; y < limit * 2; y++ {
		pascal = append(pascal, make([]int, len(pascal[y]) + 1))
		pascal[y+1][0] = 1
		for x := 1; x < len(pascal[y]); x++ {
			pascal[y+1][x] = pascal[y][x-1] + pascal[y][x]
		}
	}

	// Print entire triangle
	if debug == true {
		for y := 0; y < limit * 2; y++ {
			for x := 0; x < len(pascal[y])-1; x++ {
				fmt.Printf("%d ", pascal[y][x])
			}
			fmt.Println("")
		}
	}

	fmt.Println(pascal[limit*2][limit])
}
