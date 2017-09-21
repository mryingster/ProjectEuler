// -*- compile-command: "kotlinc problem_007.kt -include-runtime -d problem_007.jar" -*-
// Copyright (c) 2017 Michael Caldwell

fun main(args: Array<String>) {
        println("Project Euler - Problem 7:")
        println("What is the 10,001st prime number?\n")

        var count = 1
        val limit = 10001
        var sieve = IntArray(1000000, {_ -> 1})

        var n = 3
        var lastPrime = 2
        while (count < limit) {
                if (sieve[n] == 1) {
                        count++
                        lastPrime = n
                        var i = n*2
                        while (i < 1000000) {
                                sieve[i] = 0
                                i += n
                        }
                }
                n += 2
        }

        println(lastPrime)
}
