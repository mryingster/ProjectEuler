// -*- compile-command: "go build -o problem_005_go problem_005.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func isPrime(n int) bool {
	if n < 2 { return false }
	if n == 2 { return true }
	if n % 2 == 0 { return false }

	for i := 3; i*i <= n; i += 2 {
		if n % i == 0 {
			return false
		}
	}

	return true
}

func divisible(n int) bool {
	for i := 1; i <= 20; i++ {
		if n % i != 0 {
			return false
		}
	}

	return true
}

func main() {
        fmt.Println("Project Euler - Problem 5:")
        fmt.Println("What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n")

	n := 1
	limit := 20

	for i := 1; i < limit; i++ {
		if isPrime(i) {
			n *= i
		}
	}

	
	for i := 2; i < limit; i++ {
		n *= i
		if divisible(n) == true {
			break
		}
	}

        fmt.Println(n)
}

