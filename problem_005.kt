// -*- compile-command: "kotlinc problem_005.kt -include-runtime -d problem_005.jar" -*-
// Copyright (c) 2017 Michael Caldwell

fun isDivisible(n : Int): Boolean {
        for (d in 2..20) {
                if (n % d != 0) {
                        return false
                }
        }
        return true
}

fun isPrime(n : Int): Boolean {
        if (n < 2) { return false }
        if (n == 2) { return true }
        if (n % 2 == 0) { return false }

        val limit = Math.sqrt(n.toDouble()).toInt()
        for (d in 3..limit step 2) {
                if (n % d == 0) {
                        return false
                }
        }

        return true
}

fun main(args: Array<String>) {
        println("Project Euler - Problem 5:")
        println("What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n")

        var base = 1
        // Multiply primes under 20, since that is the minimum possible answer
        for (n in 2..20) {
                if (isPrime(n)) {
                        base *= n
                }
        }

        var multiplier = 1
        // Multiply base times incrementing values until it satisfies conditions
        while (isDivisible(base * multiplier) == false) {
                multiplier++
        }

        // Print the result!
        println(base * multiplier)
}

