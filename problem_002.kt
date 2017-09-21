// -*- compile-command: "kotlinc problem_002.kt -include-runtime -d problem_002.jar" -*-
// Copyright (c) 2017 Michael Caldwell

fun main(args: Array<String>) {
        println("Project Euler - Problem 2:")
        println("By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\n")

        val limit: Int = 4000000
        var n: Int = 1
        var a: Int = 0
        var sum: Int = 0

        while (n < limit) {
                val t: Int = n
                n += a
                a = t

                if (n % 2 == 0) {
                        sum += n
                }
        }

        println(sum)
}
