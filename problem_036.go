// -*- compile-command: "go build -o problem_036_go problem_036.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func reverseInt(n int) int {
	r := 0
	for n > 0 {
		r *= 10
		r += n % 10
		n /= 10
	}
	return r
}

func reverseString(s string) string {
	reverse := []rune(s)

	for a, b := 0, len(reverse)-1; a < b; a, b = a+1, b-1 {
		reverse[a], reverse[b] = reverse[b], reverse[a]
	}

	return string(reverse)
}

func binary(n int) string {
	b := ""

	// Find largest power of 2 that is smaller than n
	powerOf2 := 1
	for powerOf2 <= n {
		powerOf2 *= 2
	}
	powerOf2 /= 2

	// Subtract power of 2 from n, divide by 2
	for powerOf2 > 0 {
		if powerOf2 <= n {
			b = b + "1"
			n -= powerOf2
		} else {
			b = b + "0"
		}
		powerOf2 /= 2
	}

	return b
}

func main() {
        fmt.Println("Project Euler - Problem 36:")
        fmt.Println("Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.\n")

	limit := 1000000
	total := 0
	debug := false

	for number := 1; number < limit; number++ {
		rebmun := reverseInt(number)

		if number == rebmun {
			numberBin := binary(number)
			rebmunBin := reverseString(numberBin)

			if numberBin == rebmunBin {
				total += number

				if debug == true {
					fmt.Println(number)
					fmt.Println(binary(number))
				}
			}
		}
	}

        fmt.Println(total)
}
