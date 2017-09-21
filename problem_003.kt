// -*- compile-command: "kotlinc problem_003.kt -include-runtime -d problem_003.jar" -*-
// Copyright (c) 2017 Michael Caldwell

fun main(args: Array<String>) {
        println("Project Euler - Problem 3:")
        println("What is the largest prime factor of the number 600851475143?\n")

        var n: Long = 600851475143
        var d: Long = 1

        while (n > 1) {
                d += 1
                while (n % d == 0.toLong()) {
                        n /= d
                }
        }

        println(d)
}
