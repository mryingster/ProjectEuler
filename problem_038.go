// -*- compile-command: "go build -o problem_010_go problem_010.go" -*-
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

func isPandigital(n int) bool {
	number := []int{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}

	for n > 0 {
		number[n%10]++
		n /= 10
	}

	for i := 0; i < len(number); i++ {
		if number[i] != 1 {
			return false
		}
	}

	return true
}

func main() {
        fmt.Println("Project Euler - Problem 10:")
        fmt.Println("What is the largest 1 to 9 pandigital that can be formed by multiplying a fixed number by 1, 2, 3, ... ?\n")

	largestPandigital := 0
	debug := false

	for base := 1; base < 9999; base++ {
		number := base

		for multiplier := 2; multiplier < 5; multiplier++ {
			temp := base * multiplier
			number *= int(math.Pow(10, numLength(temp)))
			number += temp

			if number > 987654321 {
				break
			}

			if number > 123456789 {
				if isPandigital(number) {
					if number > largestPandigital {
						largestPandigital = number
						if debug == true {
							fmt.Printf("base: %d, multiplier: %d, pandigital: %d\n", base, multiplier, number)
						}
					}
				}
			}
		}
	}

	fmt.Println(largestPandigital)
}
