// -*- compile-command: "go build -o problem_030_go problem_030.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func main() {
        fmt.Println("Project Euler - Problem 30:")
        fmt.Println("Find the sum of all the numbers that can be written as the sum of fifth powers of their digits\n")

        // Precompute powers
        var powers [10]int
        for n := 0; n < 10; n++ {
                powers[n] = n * n * n * n *n
        }

        limit := 500000
        sum := 0
        for n:=10; n<limit; n++ {
                number := n
                digitSum := 0

                for number > 0 {
                        digitSum += powers[number % 10]
                        number /= 10
                }

                if digitSum == n {
                        sum += digitSum
                }
        }

        fmt.Println(sum)
}
