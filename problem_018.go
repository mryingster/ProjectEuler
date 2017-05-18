// -*- compile-command: "go build -o problem_018_go problem_018.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
	fmt.Println("Project Euler - Problem 18")
	fmt.Println("Find the maximum total from top to bottom of the triangle below:\n")

	triangle := [][]int{{75,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		     {95, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		     {17, 47, 82,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		     {18, 35, 87, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		     {20,  4, 82, 47, 65,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		     {19,  1, 23, 75,  3, 34,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		     {88,  2, 77, 73,  7, 63, 67,  0,  0,  0,  0,  0,  0,  0,  0},
		     {99, 65,  4, 28,  6, 16, 70, 92,  0,  0,  0,  0,  0,  0,  0},
		     {41, 41, 26, 56, 83, 40, 80, 70, 33,  0,  0,  0,  0,  0,  0},
		     {41, 48, 72, 33, 47, 32, 37, 16, 94, 29,  0,  0,  0,  0,  0},
		     {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,  0,  0,  0,  0},
		     {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,  0,  0,  0},
		     {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,  0,  0},
		     {63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,  0},
		     {04, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}}

	// Print triangle nicely
	for y := 0; y < len(triangle); y++ {
		for x := y; x < len(triangle); x++ {
			fmt.Printf("  ")
		}
		for x := 0; x <= y; x++ {
			fmt.Printf("%02d  ", triangle[y][x])
		}
		fmt.Println("")
	}
	fmt.Println("")

	// Work from bottom up
	for y := len(triangle) - 2; y >= 0; y-- {
		for x := 0; x <= y; x++ {
			if triangle[y+1][x] > triangle[y+1][x+1] {
				triangle[y][x] += triangle[y+1][x]
			} else {
				triangle[y][x] += triangle[y+1][x+1]
			}
		}
	}

	fmt.Println(triangle[0][0])
}
