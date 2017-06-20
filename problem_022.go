// -*- compile-command: "go build -o problem_022_go problem_022.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import (
	"fmt"
	"io/ioutil"
	"strings"
	"sort"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {
	fmt.Println("Project Euler - Problem 22:")
	fmt.Println("Sort 5000 names and calculate the sum of their name scores.\n")

	debug := false

	// Import raw text from file
	data, err := ioutil.ReadFile("problem_022.txt")
	check(err)

	// Create array to store names
	nameArray := strings.Split(string(data), ",")

	// Sort array of names alphabetically
	sort.Strings(nameArray)

	// Generate each name's score
	total := 0
	for i := 0; i < len(nameArray); i++ {
		nameScore := 0
		for c := 0; c < len(nameArray[i]); c++ {
			char := int(nameArray[i][c])
			if char == '"' { continue }
			nameScore += char - 'A' + 1			
		}

		total += nameScore * (i + 1)

		if debug == true {
			fmt.Println(nameArray[i], i, nameScore, nameScore * i, total)
		}
	}

	fmt.Println(total)
}
