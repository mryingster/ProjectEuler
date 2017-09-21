// -*- compile-command: "kotlinc problem_001.kt -include-runtime -d problem_001.jar" -*-
// Copyright (c) 2017 Michael Caldwell

fun main(args: Array<String>) {
        println("Project Euler - Problem 1:")
        println("Find the sum of all the multiples of 3 or 5 below 1000.\n")

        var total: Int = 0

        for (number in 0..1000) {
                if ( number % 3 == 0 || number % 5 == 0 ) {
                        total += number
                }
        }

        println(total)
}
