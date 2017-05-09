// -*- compile-command: "go build -o problem_003_go problem_003.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
        fmt.Println("Project Euler - Problem 3:")
        fmt.Println("What is the largest prime factor of the number 600851475143?\n")

        n := 600851475143
	factor := 2

        for factor < n {
                for n % factor == 0 {
                         n /= factor
                }
		factor++
        }

        fmt.Println(n)
}

