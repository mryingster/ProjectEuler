// -*- compile-command: "rustc -o problem_005_rs problem_005.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_prime(n: u64) -> bool {
    if n < 2 {
        return false;
    }
    if n == 2 {
        return true;
    }
    if n % 2 == 0 {
        return false;
    }

    let limit = (n as f64).sqrt() as u64;
    for i in 3..(limit+1) {
        if n % i == 0 {
            return false;
        }
    }
    return true;
}

fn main() {
    println!("Project Euler - Problem 5");
    println!("What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n");

    // Start off with a base of all primes less than 20
    // Impossible for number to be smaller than this
    let mut n = 1;
    for i in 1..20 {
        if is_prime(i) == true {
            n *= i;
        }
    }

    let mut valid = false;
    while valid == false {
        n += 10;
        valid = true;
        // No need to check 2 - 10,
        // because multiples of each are tested in range of 11-20
        for i in 11..21 {
            if n % i != 0 {
                valid = false;
                break;
            }
        }
    }

    println!("{}", n);
}
