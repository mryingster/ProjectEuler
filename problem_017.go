// -*- compile-command: "go build -o problem_017_go problem_017.go" -*-
// Copyright (c) 2017 Michael Caldwell
package main

import "fmt"

func characters(n int) int {
	switch n {
		case 	1: return 3 // one
		case 	2: return 3 // two
		case 	3: return 5 // three
		case 	4: return 4 // four
		case 	5: return 4 // five
		case 	6: return 3 // six
		case 	7: return 5 // seven
		case 	8: return 5 // eight
		case 	9: return 4 // nine
		case   10: return 3 // ten
		case   11: return 6 // eleven
		case   12: return 6 // twelve
		case   13: return 8 // thirteen
		case   14: return 8 // fourteen
		case   15: return 7 // fifteen
		case   16: return 7 // sixteen
		case   17: return 9 // seventeen
		case   18: return 8 // eighteen
		case   19: return 8 // nineteen
		case   20: return 6 // twenty
		case   30: return 6 // thirty
		case   40: return 5 // forty
		case   50: return 5 // fifty
		case   60: return 5 // sixty
		case   70: return 7 // seventy
		case   80: return 6 // eighty
		case   90: return 6 // ninety
		case  100: return 7 // hundred
		case 1000: return 8 // thousand
		default: return 0
	}
	return 0
}

func main() {
	fmt.Println("Project Euler - Problem 17")
	fmt.Println("If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?\n")

	debug := false
	totalLetters := 0

	for n := 1; n <= 1000; n++ {
		number := n
		letters := 0
		if number > 999 {
			letters += characters(number/1000)
			letters += characters(1000)
			number %= 1000
		}

		if number > 99 {
			letters += characters((number / 100))
			letters += characters(100)
			number %= 100
		}

		if n > 99 && number > 0 {
			letters += 3 // and
		}

		if number > 19 {
			letters += characters((number / 10) * 10)
			number %= 10
		}

		if number > 0 {
			letters += characters(number)
		}

		if debug == true {
			fmt.Println("Number:", n, "Characters:", letters)
		}

		totalLetters += letters
	}

	fmt.Println(totalLetters)
}
