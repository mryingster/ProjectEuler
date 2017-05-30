// -*- compile-command: "go build -o problem_023_go problem_023.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func divisorSum(n int) int {
	sum := 1
	limit := n
	for d := 2; d < limit; d++ {
		if n % d == 0 {
			sum += d
			// Short cut to eliminate unecessary searching
			limit = n / d
			if limit != d {
				sum += limit
			}
		}
	}

	return sum
}

func main() {
        fmt.Println("Project Euler - Problem 23:")
        fmt.Println("Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.\n")

	limit := 28123

	// Find all abundant numbers. Limits given to us.
	var abundantNumbers []int
	for n := 12; n < limit; n++ {
		d := divisorSum(n)
		if d > n {
			abundantNumbers = append(abundantNumbers, n)
		}
	}

	// Find all numbers that can be made with abundant sums
	abundantSums := make([]int, limit)
	for a := 0; a < len(abundantNumbers); a++ {
		for b := a; b < len(abundantNumbers); b++ {
			abundantSum := abundantNumbers[a] + abundantNumbers[b]
			if abundantSum >= limit {
				break
			}
			abundantSums[abundantSum]++
		}
	}

	// Sum all numbers that can't be made by abundant sums
	sum := 0
	for i := 0; i < len(abundantSums); i++ {
		if abundantSums[i] == 0 {
			sum += i
		}
	}

	fmt.Println(sum)
}
