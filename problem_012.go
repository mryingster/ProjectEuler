// -*- compile-command: "go build -o problem_012_go problem_012.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func numberOfDivisors(n int, primes []int) int {
	divisorCount := 1
	primeIndex := 0

	for  primeIndex < len(primes) && n > 1 {
		primeDivisorCount := 1
		for n % primes[primeIndex] == 0 {
			n /= primes[primeIndex]
			primeDivisorCount++
		}
		primeIndex++
		divisorCount *= primeDivisorCount
	}

    return divisorCount
}


func main() {
        fmt.Println("Project Euler - Problem 12:")
        fmt.Println("What is the value of the first triangle number to have over five hundred divisors?\n")

	target := 500

        var sieve [1000000]bool
        limit := len(sieve)
	var primes []int

	// Get a list of primes for factorization
        for n:=2; n<limit; n++ {
                if sieve[n] == false {
                        primes = append(primes, n)
                        for i := n; i<limit; i += n {
                                sieve[i] = true
                        }
                }
        }

	// Get our triangle numbers & divisors
        triangleHelper := 1
        triangleNumber := 1

        for numberOfDivisors(triangleNumber, primes) < target {
                triangleHelper++
                triangleNumber += triangleHelper
        }

	fmt.Println(triangleNumber)
}
