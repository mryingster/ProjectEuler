// -*- compile-command: "go build -o problem_025_go problem_025.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
        fmt.Println("Project Euler - Problem 25:")
        fmt.Println("What is the index of the first term in the Fibonacci sequence to contain 1000 digits?\n")

        index := 1
	limit := 1000
	digits := 6
        fib_old := 0
        fib_current := 1

        for digits < limit {
                fib_new := fib_current + fib_old
                fib_old = fib_current
                fib_current = fib_new

		// We don't need more than a few digits to be accurate, so
		// keep the number under 6 digits and count how many times
		// we have to shift to know how many decimals we fib has
		for fib_current > 999999 {
			fib_current /= 10
			fib_old /= 10
			digits += 1
		}

		index += 1
        }

        fmt.Println(index)
}
