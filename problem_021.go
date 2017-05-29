// -*- compile-command: "go build -o problem_021_go problem_021.go" -*-
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
			sum += limit
		}
	}

	return sum
}

func main() {
        fmt.Println("Project Euler - Problem 21:")
        fmt.Println("Evaluate the sum of all the amicable numbers under 10000.\n")

	history := make([]int, 10000)
	debug := false
	sum := 0

	for n := 10; n < 10000; n++ {
		d := divisorSum(n)
		history[n] = d

		if d < len(history) && history[d] == n  && d != n {
			if debug == true {
				fmt.Println(n, d)
			}
			sum += d + n
		}
	}

	fmt.Println(sum)
}
