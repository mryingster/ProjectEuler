// -*- compile-command: "go build -o problem_032_go problem_032.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func deconstruct(n int, d []int) []int {
        for n > 0 {
                d[n % 10]++
                n /= 10
        }
        return d
}

func isPandigital(a int, b int) bool {
        d := []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

        d = deconstruct(a, d)
        d = deconstruct(b, d)
        d = deconstruct(a * b, d)

        if d[0] != 0 {
                return false
        }

        for i := 1; i < len(d); i++ {
                if d[i] != 1 {
                        return false
                }
        }

        return true
}

func main() {
        fmt.Println("Project Euler - Problem 32:")
        fmt.Println("Find the sum of all numbers that can be written as pandigital products.\n")

        sum := 0
        limit := 2500
        history := []int{}

        for a := 1; a < limit; a++ {
                for b := a; b < limit; b++ {
                        if isPandigital(a, b) {
                                product := a * b
                                unique := true

                                // Search for uniqueness of product
                                for i := 0; i < len(history); i++ {
                                        if history[i] == product {
                                                unique = false
                                                break
                                        }
                                }

                                // Record product for future reference
                                if unique == true {
                                        sum += product
                                        history = append(history, product)
                                }
                        }
                }
        }

        fmt.Println(sum)
}
