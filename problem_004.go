// -*- compile-command: "go build -o problem_004_go problem_004.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func reverse(n int) int {
	r := 0

	for n > 0 {
		r *= 10
		r += n % 10
		n /= 10
	}

	return r
}

func main() {
        fmt.Println("Project Euler - Problem 4:")
        fmt.Println("Find the largest palindrome made from the product of two 3-digit numbers.\n")

	palindrome := 0

        for a := 100; a < 999; a++ {
		for b := a; b < 999; b++ {
			candidate := a * b
			if reverse(candidate) == candidate {
				if candidate > palindrome {
					palindrome = candidate
				}
			}
		}
        }

        fmt.Println(palindrome)
}

