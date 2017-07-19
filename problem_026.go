// -*- compile-command: "go build -o problem_026_go problem_026.go" -*-
// Copyright (c) 2016 Michael Caldwell
package main

import "fmt"

func divide(numerator int, denominator int) []int {
	n := []int{numerator}
	i := 0

	for i < 1000 {
		tmp := n[i] / denominator
		tmp2 := tmp * denominator
		n[i] -= tmp2
		n = append(n, 0)
		if n[i] < denominator {
			n[i+1] += n[i]*10
			n[i] = 0
		}
		n[i] = tmp
		i += 1
	}

	return n
}

func repeatLength(a []int) int {
	// Find beginning of number (second non-zero digit)
	start := 0
 	for i := 0; i < 10; i++ {
		if a[i] != 0 {
			start = i + 1
			break
		}
	}

	// Go through all ending positions and look for repeat
	l := 0
	for end := start + 1; end < 1000; end++ {
		repeat := true
		// Check 10 digits - good enough for verification
		for i := 0; i < 10; i++ {
			if a[start + i] != a[end + i] {
				repeat = false
				break
			}
		}
		l = end - start

		// Never found repeating characters
		if end == 999 {
			l = -1
		}

		// Finished our job!
		if repeat == true {
			break
		}
	}

	return l
}

func main() {
	fmt.Println("Project Euler - Problem 26")
	fmt.Println("Find the value of d < 1000 for which 1/d contains the longest recurring cycle. \n")

	max_l := 0
	max_n := 0
	debug := false

	for n := 2; n < 1000; n++ {
		array := divide(1, n)
		l := repeatLength(array)
		if l > max_l {
			max_l = l
			max_n = n
		}

		if debug == true {
			fmt.Println(n, l, array[0:30])
		}
	}

	fmt.Println(max_n)
}
