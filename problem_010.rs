// -*- compile-command: "rustc -o problem_010_rs problem_010.rs" -*-
// Copyright (c) 2016 Michael Caldwell
//use std::num;

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
    for i in 3..limit+1 {
        if n % i == 0 {
            return false;
        }
    }
    return true;
}


fn main() {
    println!("Project Euler - Problem 10");
    println!("Find the sum of all the primes below two million.\n");

    let mut sum: u64 = 0;

    for n in 2..1999999 {
        if is_prime(n) {
            sum += n
        }
    }

    println!("{}", sum);
}
