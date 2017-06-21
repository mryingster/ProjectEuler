// -*- compile-command: "go build -o problem_027_go problem_027.go" -*-
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

func main() {
        fmt.Println("Project Euler - Problem 27:")
        fmt.Println("Find the product of the coefficients, a and b, for the quadratic expression, n^2 + an + b, that produces the maximum number of primes for consecutive values of n, starting with n = 0.\n")

        maxPrimesProduced := 0
        maxProduct := 0
        limit := 1000

        for a := -1 * limit; a<limit; a++ {
                for b := -1 * limit; b<limit; b++ {
                        primesProduced := 0
                        for n := 0; n<1000; n++ {
                                result := (n * n) + (a * n) + b
                                if isPrime(result) {
                                        primesProduced++
                                } else {
                                        break
                                }
                        }
                        if primesProduced > maxPrimesProduced {
                                maxPrimesProduced = primesProduced
                                maxProduct = a * b
                        }
                }
        }

        fmt.Printf("%d (%d primes)\n", maxProduct, maxPrimesProduced)
}
