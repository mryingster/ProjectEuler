// -*- compile-command: "go build -o problem_010_go problem_010.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
        fmt.Println("Project Euler - Problem 10:")
        fmt.Println("Find the sum of all the primes below two million.\n")

	var sieve [2000000]bool
	limit := len(sieve)
	sum := 0

	for n:=2; n<limit; n++ {
		if sieve[n] == false {
			sum += n
			for i := n; i<limit; i += n {
				sieve[i] = true
			}
		}
	}

        fmt.Println(sum)
}
