// -*- compile-command: "go build -o problem_007_go problem_007.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
        fmt.Println("Project Euler - Problem 7:")
        fmt.Println("What is the 10,001st prime number?\n")

	var sieve [500000]bool
	count := 0
	index := 1

	for count < 10001 {
		index++
		if sieve[index] == false {
			count++
			for i := index; i<500000; i += index {
				sieve[i] = true
			}
		}
	}

        fmt.Println(index)
}
