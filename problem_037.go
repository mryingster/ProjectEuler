// -*- compile-command: "go build -o problem_037_go problem_037.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import (
	"fmt"
	"math"
)

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

func rightTrunc(n int) bool {
	n /= 10
	for n > 0 {
		if isPrime(n) == false {
			return false
		}
		n /= 10
	}

	return true
}

func leftTrunc(n int) bool {
	l := numLength(n)
	for l > 1 {
		// Get first digit
		d := n / int(math.Pow(10, l-1))

		// Multiply by 10 until right length
		// Subtract from number
		n -= d * int(math.Pow(10, l-1))

		// See if prime
		if isPrime(n) == false {
			return false
		}

		l = numLength(n)
	}

	return true
}

func main() {
        fmt.Println("Project Euler - Problem 37:")
        fmt.Println("Find the sum of the only eleven primes that are both truncatable from left to right and right to left.\n")

	total := 0
	limit := 11
	number := 11
	debug := false

	for limit > 0 {
		if isPrime(number) {
			if rightTrunc(number) {
				if leftTrunc(number) {
					if debug == true {
						fmt.Println(number)
					}
					total += number
					limit--
				}
			}
		}
		number += 2
	}

        fmt.Println(total)
}
