// -*- compile-command: "go build -o problem_002_go problem_002.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
        fmt.Println("Project Euler - Problem 2")
        fmt.Println("By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\n")

        sum := 0
	limit := 4000000

	fib_old := 1
	fib_current := 1

        for fib_current < limit {
                if fib_current % 2 == 0 {
                         sum = sum + fib_current
                }

		fib_new := fib_current + fib_old
		fib_old = fib_current
		fib_current = fib_new
        }

        fmt.Println(sum)
}

