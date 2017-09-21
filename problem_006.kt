// -*- compile-command: "kotlinc problem_006.kt -include-runtime -d problem_006.jar" -*-
// Copyright (c) 2017 Michael Caldwell

fun main(args: Array<String>) {
        println("Project Euler - Problem 6:")
        println("Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n")

        var sumOfSquares = 0
        var squareOfSums = 0

        for (n in 1..100) {
                sumOfSquares += n*n
                squareOfSums += n
        }

        squareOfSums *= squareOfSums

        println(squareOfSums - sumOfSquares)
}

