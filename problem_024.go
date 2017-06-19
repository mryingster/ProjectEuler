// -*- compile-command: "go build -o problem_024_go problem_024.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func nextPermutation(a []int) {
	// Find the largest index k such that a[k] < a[k + 1]
	k := 0
	for i := 0; i < len(a)-1; i++ {
		if a[i] < a[i+1] {
			k = i
		}
	}

	// Find the largest index l greater than k such that a[k] < a[l]
	l := 0
	for i := k; i < len(a); i++ {
		if a[k] < a[i] {
			l = i
		}
	}

	// Swap the value of a[k] with that of a[l]
	t := a[k]
	a[k] = a[l]
	a[l] = t

	// Reverse the sequence from a[k + 1] up to and including the final element a[n]
	if k < 8 {
		r := [10]int{}
		j := 9
		for i := k+1; i < len(a); i++ {
			r[j] = a[i]
			j--
		}

		for i := k+1; i < len(a); i++ {
			a[i] = r[i]
		}
	}
}

func printArray(a []int) {
	for i := 0; i < len(a); i++ {
		fmt.Print(a[i])
	}
	fmt.Println("")
}

func main() {
	fmt.Println("Project Euler - Problem 24:")
	fmt.Println("Find the 1,000,000th lexiconic permutation of the numbers 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.\n")

	array := []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	debug := false

	for i := 0; i<1000000; i++{
		nextPermutation(array)
		if debug == true {
			printArray(array)
		}
	}

	printArray(array)
}
