// -*- compile-command: "kotlinc problem_004.kt -include-runtime -d problem_004.jar" -*-
// Copyright (c) 2017 Michael Caldwell

fun reverse(input : Int): Int {
        var n = input
        var r = 0
        while (n > 0) {
                r *= 10
                r += n % 10
                n /= 10
        }
        return r
}

fun isPalindrome(n : Int): Boolean {
        if (n == reverse(n)) {
                return true
        }
        return false
}

fun main(args: Array<String>) {
        println("Project Euler - Problem 4:")
        println("Find the largest palindrome made from the product of two 3-digit numbers.\n")

        var largest = 0

        for (a in 100..999) {
                for (b in 100..999) {
                        val product = a * b
                        if (isPalindrome(product) == true && largest < product){
                                largest = product
                        }
                }
        }

        println(largest)
}

