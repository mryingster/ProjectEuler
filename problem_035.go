// -*- compile-command: "go build -o problem_035_go problem_035.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import (
	"fmt"
	"math"
)

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

func numLength(n int) float64 {
	if n == 0 {
		return 0.0
	}

	if n < 0 {
		n *= -1
	}

	digits := math.Floor(math.Log10(float64(n))) + 1;

	return digits;
}

func rotate(n int) int {
	lastDigit := n % 10
	n /= 10
	return n + lastDigit * int(math.Pow(10, numLength(n)))
}

func main() {
        fmt.Println("Project Euler - Problem 35:")
        fmt.Println("How many circular primes are there below one million?\n")

	limit := 1000000
	total := 0

	for n := 2; n < limit; n++ {
		if isPrime(n) {
			circular := true
			number := rotate(n)

			for n != number {
				if isPrime(number) == false {
					circular = false
					break
				}
				number = rotate(number)
			}

			if circular == true {
				total++
			}
		}
	}

        fmt.Println(total)
}

