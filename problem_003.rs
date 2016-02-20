// -*- compile-command: "rustc -o problem_003_rs problem_003.rs" -*-
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
    println!("Project Euler - Problem 3");
    println!("What is the largest prime factor of the number 600851475143?\n");

    let mut n: u64 = 600851475143;
    let mut d: u64 = 3;
    while n > 1 {
        d += 2;
        while is_prime(d) == false {
            d += 2;
        }

        while n % d == 0 {
            n = n / d;
        }
    }

    println!("{}", d);
}
